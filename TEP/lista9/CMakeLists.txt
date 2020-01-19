cmake_minimum_required(VERSION 3.14)
project(lista9)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(
        lista9
        main.cpp

        src/Matrix.cpp
        src/Mscn/MscnProblem.cpp
        src/Utils.cpp
        src/Timer.cpp
        src/Solvers/RandomSearch.cpp
        src/Solvers/DEvolution.cpp src/Timer.cpp include/Timer.h src/Mscn/MscnRandomProblem.cpp)