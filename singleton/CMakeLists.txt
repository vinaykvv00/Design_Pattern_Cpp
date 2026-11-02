cmake_minimum_required(VERSION 3.12)
project(SingletonPattern CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(singleton
    src/main.cpp
    src/Logger.cpp
)
