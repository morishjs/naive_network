# Install script for directory: /Users/imac/naive_network/libraries/poco

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Poco" TYPE FILE FILES
    "/Users/imac/naive_network/cmake-build-debug/libraries/poco/Poco/PocoConfig.cmake"
    "/Users/imac/naive_network/cmake-build-debug/libraries/poco/Poco/PocoConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/imac/naive_network/cmake-build-debug/libraries/poco/Foundation/cmake_install.cmake")
  include("/Users/imac/naive_network/cmake-build-debug/libraries/poco/Encodings/cmake_install.cmake")
  include("/Users/imac/naive_network/cmake-build-debug/libraries/poco/XML/cmake_install.cmake")
  include("/Users/imac/naive_network/cmake-build-debug/libraries/poco/JSON/cmake_install.cmake")
  include("/Users/imac/naive_network/cmake-build-debug/libraries/poco/Util/cmake_install.cmake")
  include("/Users/imac/naive_network/cmake-build-debug/libraries/poco/Net/cmake_install.cmake")
  include("/Users/imac/naive_network/cmake-build-debug/libraries/poco/MongoDB/cmake_install.cmake")
  include("/Users/imac/naive_network/cmake-build-debug/libraries/poco/Redis/cmake_install.cmake")
  include("/Users/imac/naive_network/cmake-build-debug/libraries/poco/Data/cmake_install.cmake")
  include("/Users/imac/naive_network/cmake-build-debug/libraries/poco/Zip/cmake_install.cmake")
  include("/Users/imac/naive_network/cmake-build-debug/libraries/poco/PageCompiler/cmake_install.cmake")
  include("/Users/imac/naive_network/cmake-build-debug/libraries/poco/PageCompiler/File2Page/cmake_install.cmake")

endif()

