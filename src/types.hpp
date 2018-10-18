#ifndef NAIVE_NETWORK_TYPES_HPP
#define NAIVE_NETWORK_TYPES_HPP

#include <string>
#include "crypto/sha256.hpp"

namespace naive {
    using block_id = crypto::sha256;
    using transaction_id = crypto::sha256;
    using std::string;
}

#endif //NAIVE_NETWORK_TYPES_HPP
