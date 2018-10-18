cmake_minimum_required(VERSION 3.12)
project(naive_network)

set(CMAKE_CXX_STANDARD 11)
set(CRYPTO src/crypto/sha256.hpp src/crypto/sha256.cpp src/crypto/hex.cpp src/crypto/hex.hpp src/transaction.cpp src/transaction.hpp src/net/tracker.cpp src/net/tracker.hpp)
add_executable(naive_network main.cpp ${CRYPTO})