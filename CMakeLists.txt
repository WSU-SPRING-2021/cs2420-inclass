cmake_minimum_required(VERSION 3.10)

project(cs2420_inclass_project)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(main src/main.cpp src/student.cpp)
add_executable(main-linked src/main-linked.cpp)
add_executable(ptr src/pointer.cpp src/student.cpp)
add_executable(main-stack src/main-stack.cpp)
add_executable(main-queue src/main-queue.cpp)
add_executable(maze src/maze.cpp)

add_executable(chained src/chained.cpp)
add_executable(sort src/main-sort.cpp)
add_executable(bst src/main-bst.cpp)
add_executable(avl src/main-avl.cpp)