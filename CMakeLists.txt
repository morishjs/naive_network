cmake_minimum_required(VERSION 3.12)
project(naive_network)

set(CMAKE_CXX_STANDARD 11)
set(CRYPTO chain/crypto/sha256.hpp chain/crypto/sha256.cpp chain/crypto/hex.cpp chain/crypto/hex.hpp chain/transaction.cpp chain/transaction.hpp)
add_executable(naive_network main.cpp ${CRYPTO})