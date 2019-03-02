cmake_minimum_required(VERSION 2.8)
project(project2)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(project2renewed main.cpp BinaryHeap.cpp Person.cpp Day.cpp Counter.cpp BinaryHeap.h Person.h Counter.h Day.h Simultaneity.cpp Simultaneity.h)