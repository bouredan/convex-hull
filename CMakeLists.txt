cmake_minimum_required(VERSION 3.16)
project(convex_hull)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        convex_hull
        main.cpp
        src/input_output.cpp
        src/input_output.h
        src/convex_hull.cpp
        src/convex_hull.h
)