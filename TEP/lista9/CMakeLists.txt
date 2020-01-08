cmake_minimum_required(VERSION 3.14)
project(lista9)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        lista9
        main.cpp

        src/Matrix.cpp
        src/MscnProblem.cpp
        src/Utils.cpp
        src/Random.cpp
        src/RandomSearch.cpp include/RandomSearch.h)