#include "chain.hpp"

namespace naive {
    static chain& chain::get_chain() {
        static chain block_chain;
        return block_chain;
    }
}

