cmake_minimum_required(VERSION 3.19)
project(homework3_HashTables)

set(CMAKE_CXX_STANDARD 14)

add_executable(homework3_HashTables main.cpp HashTable.cpp student.h HashTable.h student.cpp QuadraticHashing.cpp QuadraticHashing.h)