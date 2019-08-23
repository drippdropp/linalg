cmake_minimum_required(VERSION 3.14)
project(gramschmidt)

set(CMAKE_CXX_STANDARD 14)
include_directories(includes)
add_executable(gramschmidt main.cpp includes/linalg.h)