cmake_minimum_required(VERSION 3.28)
project(triangulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(triangulator main.cpp
        DataStructures/Octree.hpp
        DataStructures/Octree.hpp
        IO/Input.hpp
        DataStructures/VoxelGrid.hpp
        IO/Output.hpp)
