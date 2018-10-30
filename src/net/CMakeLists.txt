project(net)
cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 11)
file(GLOB NET "*.cpp")
find_package(Boost REQUIRED COMPONENTS thread system)
message("Debug ${CMAKE_INSTALL_PREFIX}")
include_directories(${Boost_INCLUDE_DIRS})
add_library(naive_net ${NET})
