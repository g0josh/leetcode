cmake_minimum_required(VERSION 3.5)

project(leetcode VERSION 1.0.0 LANGUAGES CXX)

add_library(
    array-easy
    include/array_easy.hpp 
    src/array_easy.cpp
)

add_executable(leetcode src/main.cpp)

target_link_libraries(leetcode PRIVATE array-easy)
