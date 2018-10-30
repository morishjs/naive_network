cmake_minimum_required(VERSION 3.12)
project(naive_network)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH /Users/naive_network)
set(CRYPTO src/crypto/sha256.hpp src/crypto/sha256.cpp src/crypto/hex.cpp src/crypto/hex.hpp src/transaction.cpp src/transaction.hpp)
IF(APPLE)
    find_package(Boost COMPONENTS thread system unit_test_framework REQUIRED)
ENDIF(APPLE)

add_subdirectory(tests)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(naive_network main.cpp ${CRYPTO})
target_link_libraries(naive_network ${Boost_LIBRARIES})
