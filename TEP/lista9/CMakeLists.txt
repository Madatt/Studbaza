cmake_minimum_required(VERSION 3.14)
project(lista9)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        lista9
        main.cpp

        src/Matrix.cpp
        src/Mscn/MscnProblem.cpp
        src/Utils.cpp
        src/Solvers/RandomSearch.cpp
        src/Solvers/DEvolution.cpp)