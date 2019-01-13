cmake_minimum_required(VERSION 3.12)
project(DateTime)

set(CMAKE_CXX_STANDARD 17)

add_executable(DateTime main.cpp src/Date.cpp src/Date.h src/TimeStamp.cpp src/TimeStamp.h)