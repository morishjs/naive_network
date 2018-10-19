#include <iostream>

#include "src/chain.hpp"
#include "boost/asio.hpp"
#include "src/net/net.hpp"

using namespace boost::asio;
using namespace boost::asio::ip;
using namespace naive;

int main() {
    net controller;
    controller.initialize();

    chain block_chain;
}