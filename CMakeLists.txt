cmake_minimum_required(VERSION 3.24)
project(BOM)

set(CMAKE_CXX_STANDARD 17)

find_package(cpprestsdk REQUIRED)

add_executable(BOM main.cpp)
target_link_libraries(BOM PRIVATE cpprestsdk::cpprest)
