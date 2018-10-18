#include <sstream>
#include <algorithm>
#include <string>

#include "hex.hpp"

namespace naive {
    namespace crypto {
        uint8_t from_hex( char c ) {
            if( c >= '0' && c <= '9' )
                return c - '0';
            if( c >= 'a' && c <= 'f' )
                return c - 'a' + 10;
            if( c >= 'A' && c <= 'F' )
                return c - 'A' + 10;

            return 0;
        }

        size_t from_hex(const std::string &hex_str, char* out_data) {
            std::string::const_iterator i = hex_str.begin();
            size_t out_data_len = sizeof(*out_data);

            auto out_pos = (uint8_t*)out_data;
            auto out_end = out_pos + out_data_len;
            while( i != hex_str.end() && out_end != out_pos ) {
                *out_pos = from_hex( *i ) << 4u;
                ++i;
                if( i != hex_str.end() )  {
                    *out_pos |= from_hex( *i );
                    ++i;
                }
                ++out_pos;
            }
            return out_pos - (uint8_t*)out_data;
        }
    }
}