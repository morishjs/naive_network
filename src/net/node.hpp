//
// Created by Junsuk Park on 18/10/2018.
//

#ifndef NAIVE_NETWORK_NODE_HPP
#define NAIVE_NETWORK_NODE_HPP

#include "Poco/Net/IPAddress.h"

class node {
private:
    Poco::Net::IPAddress ia;
public:
    void refresh_peer_list(node other);
};
#endif //NAIVE_NETWORK_NODE_HPP
