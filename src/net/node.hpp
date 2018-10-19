//
// Created by Junsuk Park on 18/10/2018.
//

#ifndef NAIVE_NETWORK_NODE_HPP
#define NAIVE_NETWORK_NODE_HPP

namespace naive {
    class node {
    public:
        void refresh_peer_list(node other);
        void init_connect();
    };
}
#endif //NAIVE_NETWORK_NODE_HPP
