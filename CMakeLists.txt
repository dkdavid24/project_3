cmake_minimum_required(VERSION 3.17)
project(project_3 C)

set(CMAKE_C_STANDARD 11)

add_executable(project_3 main.c linked_list.c linked_list.h BinaryTree.c BinaryTree.h Heap.h Heap.c name.h name.c array.c array.h hash.c hash.h)