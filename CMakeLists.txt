cmake_minimum_required(VERSION 3.19)
project(c C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(arrays ${SOURCE_FILES})