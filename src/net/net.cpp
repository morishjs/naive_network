#include <algorithm>

#include "net.hpp"
#include "node.hpp"
#include "config.hpp"

#include "boost/asio.hpp"
#include "pinger.hpp"

using namespace boost::asio;
using namespace boost::asio::ip;
using std::string;

namespace naive {
    void net::initialize() {
        // TODO:
        // 1. 접속할 수 있는 Peer 리스트를 가져와야 함
        // 2. 접속한 피어들을 자신의 list에 등록하고 상대방 peer도 자신을 등록할 수 있도록 해야 함(handshake)
        // 3. 각종 이벤트 핸들러 등록 (thread)

        const string my_address = "127.0.0.1";
        node my = node(my_address);
        auto peer_list = get_peerlist();

        for (auto peer : peer_list) {
            bool alive = is_alive(peer);
            if (alive)
                node_list.push_back(peer);
        }
//        for_each(node_list.begin(), node_list.end(), [&my](node &n) {
//            n.refresh_peer_list(my);
//        });
    }

    net::node_vector net::get_peerlist() {
        node_vector v;
        auto peer_host_list = config().peer_host_list;
        std::for_each(peer_host_list.begin(), peer_host_list.end(), [&v](string &host) {
            node n = node(host);
            v.push_back(n);
        });

        return v;
    }

    bool net::is_alive(const node &other) {
        io_context io;
        pinger ping(io, other.get_ip().to_string());
        io.run();

        auto result = ping.get_state();
        return result;
    }

    void net::start() {

    }

    void net::shutdown() {

    }
}
