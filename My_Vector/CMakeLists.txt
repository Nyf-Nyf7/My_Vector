cmake_minimum_required(VERSION 3.10)
project(MyVector)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(app 
    src/my_float.cpp
    src/my_satur.cpp
    src/test.cpp
)


target_include_directories(app PRIVATE includes)