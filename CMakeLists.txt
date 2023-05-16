cmake_minimum_required(VERSION 3.5)

project(hasing1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hasing1 main.cpp
                       entry.cpp
                       hash_table.cpp)
