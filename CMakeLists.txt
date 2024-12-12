cmake_minimum_required(VERSION 3.29)
project(COMP2522_finals C)

set(CMAKE_C_STANDARD 11)

include_directories(sorting)
include_directories(stack)

add_executable(COMP2522_finals
    stack/stack.c
    stack/stack.h)
