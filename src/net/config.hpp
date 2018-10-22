#ifndef NAIVE_NETWORK_CONFIG_HPP
#define NAIVE_NETWORK_CONFIG_HPP

#include <string>
#include <vector>

namespace naive {
    class config {
    public:
        const std::vector<std::string> peer_host_list = {
                "127.0.0.1"
        };
    };
}
#endif //NAIVE_NETWORK_CONFIG_HPP
