#ifndef NAIVE_NETWORK_SHA256_HPP
#define NAIVE_NETWORK_SHA256_HPP

#include <string>

namespace naive {
    namespace crypto {
        using std::string;

        class sha256 {
        public:
            sha256() = default;
            // TODO: 직접 구현하지말고 구현되어있는 라이브러리 찾아보자.
            explicit sha256(const string& hex_str);
        private:
            uint64_t _hash[4];
        };
    }
}
#endif //NAIVE_NETWORK_SHA256_HPP
