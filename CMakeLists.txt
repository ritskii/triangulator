cmake_minimum_required(VERSION 3.28)
project(triangulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(triangulator main.cpp
        IO/Reader.hpp
        DataStructure/Octree.hpp
        DataStructure/Octree.hpp)
