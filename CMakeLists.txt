cmake_minimum_required(VERSION 3.2)
project(linker_error_example)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -isystem /home/sehe/custom/boost_1_62_0")

set(SOURCE_FILES main.cpp example.cpp) # types.cpp
add_executable(linker_error_example ${SOURCE_FILES})
