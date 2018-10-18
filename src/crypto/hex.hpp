#ifndef NAIVE_NETWORK_HEX_HPP
#define NAIVE_NETWORK_HEX_HPP

#include <string>

namespace naive {
    namespace crypto {
        uint8_t from_hex( char c );
        size_t from_hex(const std::string& hex_str, char* hash);
    }
}
#endif //NAIVE_NETWORK_HEX_HPP
