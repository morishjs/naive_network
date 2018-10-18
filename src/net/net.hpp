#ifndef NAIVE_NETWORK_NET_HPP
#define NAIVE_NETWORK_NET_HPP

#include <vector>

namespace naive {
    class node;

    class net {
        using node_vector = std::vector<node>;
    private:
        node_vector node_list;

        node_vector get_peerlist();

        bool is_alive();

    public:
        void initialize();

        void start();

        void shutdown();
    };
}
#endif //NAIVE_NETWORK_NET_HPP
