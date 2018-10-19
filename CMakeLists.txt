cmake_minimum_required(VERSION 3.12)
project(naive_network)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH /Users/naive_network)
set(CRYPTO src/crypto/sha256.hpp src/crypto/sha256.cpp src/crypto/hex.cpp src/crypto/hex.hpp src/transaction.cpp src/transaction.hpp)
set(NET src/net/net.hpp src/net/net.cpp src/net/node.cpp src/net/node.hpp)
IF(APPLE)
    set(Poco_DIR /usr/local/Cellar/poco/1.9.0_1/lib/cmake/Poco)
ENDIF(APPLE)

find_package(Poco REQUIRED COMPONENTS Foundation Net Zip)
add_executable(naive_network main.cpp ${CRYPTO} ${NET})

target_link_libraries(naive_network PUBLIC Poco::Foundation Poco::Zip Poco::Net)