cmake_minimum_required(VERSION 3.20)
project(j_dat)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
include_directories(src/include)

add_executable(j_date main.cpp)
target_link_libraries(src)
