cmake_minimum_required(VERSION 3.14)
project(lista8)

set(CMAKE_CXX_STANDARD 11)
set(GCC_COVERAGE_COMPILE_FLAGS "-fno-elide-constructors")


add_executable(lista8 lista2.cpp table.cpp)

target_compile_options(lista8 PRIVATE -fno-elide-constructors)
