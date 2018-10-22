#ifndef NAIVE_NETWORK_NET_HPP
#define NAIVE_NETWORK_NET_HPP

#include <vector>
#include "node.hpp"

namespace naive {
    using naive::node;
    class node;

    class net {
        using node_vector = std::vector<node>;
    private:
        node_vector node_list;

        node_vector get_peerlist();
        bool is_alive(const node& other);
    public:
        void initialize();

        void start();

        void shutdown();
    };
}
#endif //NAIVE_NETWORK_NET_HPP
