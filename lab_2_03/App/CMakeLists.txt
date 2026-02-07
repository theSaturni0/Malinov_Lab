cmake_minimum_required(VERSION 3.10)
project(App)

set(CMAKE_CXX_STANDARD 20)

add_executable(App main.cpp)

target_link_libraries(App PRIVATE ConverterLib)