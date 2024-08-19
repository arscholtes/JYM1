cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        degree.h
        student.h
        student.cpp
        roster.h
        roster.cpp)
