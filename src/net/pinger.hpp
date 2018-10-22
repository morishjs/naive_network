#ifndef NAIVE_NETWORK_PINGER_HPP
#define NAIVE_NETWORK_PINGER_HPP

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <istream>
#include <iostream>
#include <ostream>

#include "icmp_header.hpp"
#include "ipv4_header.hpp"

using boost::asio::ip::icmp;
using boost::asio::deadline_timer;
using boost::asio::io_context;
using boost::asio::streambuf;
using namespace std::chrono;
namespace posix_time = boost::posix_time;

class pinger
{
public:
    pinger(io_context& io_context, const std::string& destination)
            : resolver_(io_context), socket_(io_context, icmp::v4()),
              timer_(io_context), sequence_number_(0), num_replies_(0)
    {
        destination_ = *resolver_.resolve(icmp::v4(), destination, "").begin();

        start_send();
        start_receive();
    }

    bool get_state() {
        return result;
    }

private:
    void start_send()
    {
        std::string body("\"Hello!\" from Asio ping.");

        // Create an ICMP header for an echo request.
        icmp_header echo_request;
        echo_request.type(icmp_header::echo_request);
        echo_request.code(0);
        echo_request.identifier(get_identifier());
        echo_request.sequence_number(++sequence_number_);
        compute_checksum(echo_request, body.begin(), body.end());

        // Encode the request packet.
        streambuf request_buffer;
        std::ostream os(&request_buffer);
        os << echo_request << body;

        // Send the request.
        time_sent_ = boost::asio::steady_timer::clock_type::now();
        socket_.send_to(request_buffer.data(), destination_);

        // Wait up to five seconds for a reply.
        num_replies_ = 0;
        timer_.expires_at(time_sent_ + std::chrono::seconds(5));
        timer_.async_wait(boost::bind(&pinger::handle_timeout, this));
    }

    void handle_timeout()
    {
        if (num_replies_ == 0) {
            std::cout << "Request timed out" << std::endl;
            result = false;
        }
    }

    void start_receive()
    {
        // Discard any data already in the buffer.
        reply_buffer_.consume(reply_buffer_.size());

        // Wait for a reply. We prepare the buffer to receive up to 64KB.
        socket_.async_receive(reply_buffer_.prepare(65536),
                              boost::bind(&pinger::handle_receive, this, _2));
    }

    void handle_receive(std::size_t length)
    {
        // The actual number of bytes received is committed to the buffer so that we
        // can extract it using a std::istream object.
        reply_buffer_.commit(length);

        // Decode the reply packet.
        std::istream is(&reply_buffer_);
        ipv4_header ipv4_hdr;
        icmp_header icmp_hdr;
        is >> ipv4_hdr >> icmp_hdr;

        // We can receive all ICMP packets received by the host, so we need to
        // filter out only the echo replies that match the our identifier and
        // expected sequence number.
        if (is && icmp_hdr.type() == icmp_header::echo_reply
            && icmp_hdr.identifier() == get_identifier()
            && icmp_hdr.sequence_number() == sequence_number_)
        {
            // If this is the first reply, interrupt the five second timeout.
            if (num_replies_++ == 0)
                timer_.cancel();

            // Print out some information about the reply packet.
            steady_clock::time_point now = steady_clock::now();
            steady_clock::duration elapsed = now - time_sent_;
            std::cout << length - ipv4_hdr.header_length()
                      << " bytes from " << ipv4_hdr.source_address()
                      << ": icmp_seq=" << icmp_hdr.sequence_number()
                      << ", ttl=" << ipv4_hdr.time_to_live()
                      << ", time="
                      << duration_cast<milliseconds>(elapsed).count()
                      << std::endl;

            result = true;
            return;
        }

        start_receive();
    }

    static unsigned short get_identifier()
    {
#if defined(ASIO_WINDOWS)
        return static_cast<unsigned short>(::GetCurrentProcessId());
#else
        return static_cast<unsigned short>(::getpid());
#endif
    }

    icmp::resolver resolver_;
    icmp::endpoint destination_;
    icmp::socket socket_;
    boost::asio::steady_timer timer_;
    unsigned short sequence_number_;
    steady_clock::time_point time_sent_;
    streambuf reply_buffer_;
    std::size_t num_replies_;
    bool result = false;
};
#endif //NAIVE_NETWORK_PINGER_HPP
