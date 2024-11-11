cmake_minimum_required(VERSION 3.29)
project(BMP_writer)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME} main.cpp
        BMP.cpp
        BMP.h
)
