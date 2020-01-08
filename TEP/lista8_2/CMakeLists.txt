cmake_minimum_required(VERSION 3.14)
project(lista8_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(lista8_2 main.cpp table.cpp)

#target_compile_options(lista8_2 PRIVATE -fno-elide-constructors)
