#define BOOST_TEST_MODULE p2p_test

#include <boost/test/unit_test.hpp>
#include "../src/net/net.hpp"

BOOST_AUTO_TEST_SUITE(net)

    BOOST_AUTO_TEST_CASE(first_test) {
        naive::net n;
        n.initialize();
        BOOST_TEST(true);
    }

BOOST_AUTO_TEST_SUITE_END()
