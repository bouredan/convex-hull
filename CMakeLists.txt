cmake_minimum_required(VERSION 3.17)
project(convex_hull)

set(CMAKE_CXX_STANDARD 14)

add_executable(convex_hull main.cpp src/input_generator.cpp src/input_generator.h)