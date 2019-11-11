cmake_minimum_required(VERSION 3.14)
project(lista4)

set(CMAKE_CXX_STANDARD 98)

add_executable(lista4 main.cpp CFileLastError.cpp CFileLastError.h CFileThrowEx.cpp CFileThrowEx.h cmake-build-debug/CFileErrCode.cpp cmake-build-debug/CFileErrCode.h)