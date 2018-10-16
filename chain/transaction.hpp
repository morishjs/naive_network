#ifndef NAIVE_NETWORK_TRANSACTION_HPP
#define NAIVE_NETWORK_TRANSACTION_HPP

#include <cstdint>
#include "types.hpp"

namespace naive {
    struct transaction_header {
        transaction_header() = default;
        transaction_header(const transaction_header&) = default;
        transaction_header& operator=(const transaction_header&) = delete;

        uint32_t expiry_time;
    };

    struct transaction : public transaction_header {
        transaction() = delete;
        explicit transaction(const transaction_header& th): transaction_header(th) {}

        transaction_id id;
    };
}
#endif //NAIVE_NETWORK_TRANSACTION_HPP
