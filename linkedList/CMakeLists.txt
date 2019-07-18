cmake_minimum_required(VERSION 3.8)
project(linkedList)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LinkedList.h)
add_executable(linkedList ${SOURCE_FILES})