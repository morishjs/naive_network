cmake_minimum_required(VERSION 3.11)
enable_testing()

find_package(Boost COMPONENTS system unit_test_framework REQUIRED)
#set(UNIT_TESTS_INCLUDES ../src/net)
file(GLOB UNIT_TEST_SOURCE_FILES "*.cpp")

add_definitions(-DBOOST_TEST_DYN_LINK)
add_executable(p2p_test ${UNIT_TEST_SOURCE_FILES} ../src/net/net.hpp ../src/net/net.cpp)

target_include_directories(p2p_test PRIVATE ${Boost_INCLUDE_DIR})
#target_include_directories(p2p_test PRIVATE ${UNIT_TESTS_INCLUDES})

target_link_libraries(p2p_test ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
add_test(test p2p_test)