cmake_minimum_required(VERSION 3.10)
project(ConverterLib)

set(CMAKE_CXX_STANDARD 20)

add_library(ConverterLib STATIC library.cpp)

target_include_directories(ConverterLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})