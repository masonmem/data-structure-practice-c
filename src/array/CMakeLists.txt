cmake_minimum_required(VERSION 3.19)
set(CMAKE_C_STANDARD 99)

project(c_practice)

# Create library called "array" which includes our Array library
add_library(Array array.c)

# Make sure compiler can find includes for Array library
# when other libraries or executables link to Array library
target_include_directories(Array PUBLIC $(CMAKE_CURRENT_SOURCE_DIR))

# Include utility library for debugging, shared functions
target_include_directories(Array PUBLIC ../genutils)
target_link_libraries(Array LINK_PUBLIC GenUtils)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(Array PUBLIC DEBUG=1)
endif()