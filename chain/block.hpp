#ifndef NAIVE_NETWORK_BLOCK_HPP
#define NAIVE_NETWORK_BLOCK_HPP

#include <string>

namespace naive {
    class block {
        // TODO: block index type?
    public:
        block() = delete;
        block(uint32_t pindex, const std::string &pprevious_hash, uint32_t ptimestamp, const std::string &pdata,
              const std::string &phash) :
                index(pindex),
                previous(pprevious_hash),
                timestamp(ptimestamp),
                data(pdata),
                hash(phash) {}

    private:
        uint32_t index;
        std::string previous;
        uint32_t timestamp;
        std::string data;
        std::string hash;
    };
}

#endif //NAIVE_NETWORK_BLOCK_HPP
