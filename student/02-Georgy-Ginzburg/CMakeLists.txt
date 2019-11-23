cmake_minimum_required(VERSION 3.15)
project(02_Georgy_Ginzburg C)

set(CMAKE_C_FLAGS "-std=c11")
set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(01)
include_directories(02)
include_directories(03)
include_directories(04)
include_directories(05)
include_directories(06)

#add_executable(
#        05/copyfile.c
#        05/double_linked_with_arbitrary_args.c
#        05/double_linked_with_arbitrary_args.h
#        05/stack.c
#        05/stack.h
#        06/queue.c
#        06/queue.h)

add_executable(double_linked_with_arbitrary_args 05/double_linked_with_arbitrary_args.c)
add_executable(stack 05/stack.c)
add_executable(queue 06/queue.c 06/main.c)

add_executable(binary_tree 07/binary_tree.c)
add_executable(matrices 08/matrices.c)
add_executable(list_traversals 08/list_traversals.c)