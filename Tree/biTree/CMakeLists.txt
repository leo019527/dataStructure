cmake_minimum_required(VERSION 3.8)
project(biTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        BiNode.cpp
        BiNode.h
        BiTree.cpp
        BiTree.h
        main.cpp)

add_executable(biTree ${SOURCE_FILES})