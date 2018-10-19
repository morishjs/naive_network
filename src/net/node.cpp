#include "node.hpp"
#include "boost/asio/ip/tcp.hpp"

namespace naive {
    void node::init_connect() {
        io_context context;
        tcp::socket socket(context);
        tcp::resolver resolver(context);

        tcp::resolver::query q {"127.0.0.1", "80"};
        resolver.async_resolve(q, [&socket](const boost::system::error_code &ec, tcp::resolver::iterator it){
            if(!ec) {
                socket.async_connect(*it, [&socket](const boost::system::error_code &ec) {
                    if(!ec) {
                        socket.async_write_some(asio::buffer())
                    }
                });
            }
        });

        context.run();
    }
}