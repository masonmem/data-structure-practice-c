cmake_minimum_required(VERSION 3.19)
set(CMAKE_C_STANDARD 99)

project(c_practice)

# Create library called "genutils" which includes our shared utility
# functions and debug logic
add_library(GenUtils genutils.c)

# Make sure compiler can find includes for genutils library
# when other libraries or executables link to Array library
target_include_directories(GenUtils PUBLIC $(CMAKE_CURRENT_SOURCE_DIR))

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(GenUtils PUBLIC DEBUG=1)
endif()