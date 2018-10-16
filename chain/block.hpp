#ifndef NAIVE_NETWORK_BLOCK_HPP
#define NAIVE_NETWORK_BLOCK_HPP

#include <string>
#include "types.hpp"

namespace naive {
    struct block_header {
        // TODO: block index type?
        uint32_t timestamp;

        block_id previous;
        block_id id;
    };
}
#endif //NAIVE_NETWORK_BLOCK_HPP
