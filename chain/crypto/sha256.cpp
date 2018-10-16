#include "sha256.hpp"
#include "hex.hpp"


namespace naive {
    namespace crypto {
        naive::crypto::sha256::sha256(const string& hex_str) {
            auto bytes_written = crypto::from_hex(hex_str, (char*)_hash);
            if(bytes_written < sizeof(_hash)) {
                memset((char*)_hash + bytes_written, 0, (sizeof(_hash) - bytes_written));
            }
        }
    }
}

