cmake_minimum_required(VERSION 3.14)
project(c_2019 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-lm")
add_executable(1 01/1.c)
add_executable(2 02/2.c)
add_executable(03 03/03.c)
add_executable(04 04/single_linked.c)
add_executable(single_linked 04/single_linked.c)

add_executable(double_linked 04/double_linked.c)