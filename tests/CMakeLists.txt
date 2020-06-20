# CXX settings
cmake_minimum_required(VERSION 3.8)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)

# Googletest
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../externals/googletest ${CMAKE_CURRENT_BINARY_DIR}/gtest)

# Unittest
project(sort_unittest
        LANGUAGES CXX C)
file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_executable(sort_unittest ${srcs})
target_compile_options(sort_unittest PRIVATE
    $<$<CXX_COMPILER_ID:Clang>:-Werror -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-global-constructors>
    $<$<CXX_COMPILER_ID:GNU>:-Werror -Wall -Wextra -pedantic>
)
target_include_directories(sort_unittest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(sort_unittest PRIVATE gtest gtest_main)
add_test(sortgtest sort_unittest)
