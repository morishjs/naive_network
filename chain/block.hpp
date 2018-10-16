#ifndef NAIVE_NETWORK_BLOCK_HPP
#define NAIVE_NETWORK_BLOCK_HPP

#include "types.hpp"
#include "transaction.hpp"

namespace naive {
    struct block_header {
        block_header(const block_header&) = default;
        block_header& operator=(const block_header&) = delete;

        // TODO: block index type?
        uint32_t timestamp;

        block_id previous;
        block_id id;
    };

    struct block : public block_header {
        explicit block(const block_header& bh): block_header(bh) {}
    };
}
#endif //NAIVE_NETWORK_BLOCK_HPP
