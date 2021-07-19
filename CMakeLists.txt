cmake_minimum_required(VERSION 3.19)
set(CMAKE_C_STANDARD 99)

project(c_practice)

add_subdirectory(src/array)
add_subdirectory(src/genutils)
add_subdirectory(src/libs)

add_subdirectory(tst/array)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(Array PUBLIC DEBUG=1)
    target_compile_definitions(GenUtils PUBLIC DEBUG=1)
endif()