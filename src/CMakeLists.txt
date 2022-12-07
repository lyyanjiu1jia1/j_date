cmake_minimum_required(VERSION 3.20)
project(src)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

aux_source_directory(source SRC_DIR)

add_library(src STATIC ${SRC_DIR})
