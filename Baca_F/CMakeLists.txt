cmake_minimum_required(VERSION 3.16)
project(DrzewoOwocowe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DrzewoOwocowe
        main.cpp
        tree.cpp
        branch.cpp
        fruit.cpp
        garden.cpp
)