//
// Created by Junsuk Park on 18/10/2018.
//

#ifndef NAIVE_NETWORK_NODE_HPP
#define NAIVE_NETWORK_NODE_HPP

#include "boost/asio/ip/address.hpp"
#include <string>

using std::string;
using namespace boost::asio::ip;

namespace naive {
    class node {
    public:
        node() = delete;
        node(const string& host) {
            ip = ip.from_string(host);
            if(!ip.is_v4())
                ip = ip.from_string("127.0.0.1");
        }

        const address &get_ip() const {
            return ip;
        }

        void refresh_peer_list(node other);

    private:
        address ip;
    };
}
#endif //NAIVE_NETWORK_NODE_HPP
