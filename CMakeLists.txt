# CXX settings
cmake_minimum_required(VERSION 3.8)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)

# Release or Debug
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
endif()

# Project
project(sort
        LANGUAGES CXX C)
file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(sort ${srcs})
target_compile_options(sort PRIVATE
    $<$<CXX_COMPILER_ID:Clang>:-Werror -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic>
    $<$<CXX_COMPILER_ID:GNU>:-Werror -Wall -Wextra -pedantic>
)
target_include_directories(sort PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Unittest
option(BUILD_SORT_UNITTEST "Build unittest if on" OFF)
if(BUILD_SORT_UNITTEST)
    enable_testing()
    include(CTest)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()
