cmake_minimum_required(VERSION 3.5)
project(untitled1ssh2)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(SSH2_INC_PATH ${CMAKE_SOURCE_DIR}/include/openssh2)
set(CURL_INC_PATH ${CMAKE_SOURCE_DIR}/include/curl)

SET(CMAKE_SKIP_BUILD_RPATH  FALSE)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
SET(CMAKE_INSTALL_RPATH "")
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)

link_directories(${CMAKE_BINARY_DIR})

include_directories(${SSH2_INC_PATH})
include_directories(${CURL_INC_PATH})

add_executable(untitled1ssh2  utilFTP.cpp utilFTP.h maintest.cpp)
target_link_libraries(untitled1ssh2 libssh2.so libcrypto.so libssl.so libcurl.so)
set_target_properties(untitled1ssh2 PROPERTIES LINK_FLAGS "-Wl,-rpath,./")
