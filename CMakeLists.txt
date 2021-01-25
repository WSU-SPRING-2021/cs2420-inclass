cmake_minimum_required(VERSION 3.19)

project(cs2420_inclass_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(main src/main.cpp)
add_executable(ptr src/pointer.cpp)