cmake_minimum_required(VERSION 3.29)
project(laba_1)

set(CMAKE_CXX_STANDARD 23)

find_package(fmt REQUIRED)

add_executable(laba_1 main.cpp
        List.cpp
        List.h)
target_link_libraries(laba_1 fmt::fmt)
