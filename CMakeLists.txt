cmake_minimum_required(VERSION 3.8)
project(XBuild)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
include(LLVM)
add_subdirectory(sample)
add_subdirectory(xbuild)