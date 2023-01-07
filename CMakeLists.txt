cmake_minimum_required(VERSION 3.24)
project(SW_Expert_Academy_preTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(SW_Expert_Academy_preTest num2.cpp test.cpp num1.cpp)

add_executable(num2 num2.cpp num1.cpp)
add_executable(test test.cpp)
add_executable(num1 num1.cpp)