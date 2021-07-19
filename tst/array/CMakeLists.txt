cmake_minimum_required(VERSION 3.19)
set(CMAKE_C_STANDARD 99)

project(c_practice)

add_executable(RunArrayTest test_array.c ../../src/libs/unity/unity.c)

target_include_directories(RunArrayTest PUBLIC ../../src/array)
target_link_libraries(RunArrayTest LINK_PUBLIC Array)

target_include_directories(RunArrayTest PUBLIC ../../src/libs)
target_link_libraries(RunArrayTest LINK_PUBLIC Unity)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(RunArrayTest PUBLIC DEBUG=1)
endif()