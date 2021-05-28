cmake_minimum_required(VERSION 3.17)
project(project_3 C)

set(CMAKE_C_STANDARD 11)

add_executable(project_3 main.c dataStructure/linked_list.c dataStructure/linked_list.h dataStructure/BinaryTree.c dataStructure/BinaryTree.h dataStructure/Heap.h dataStructure/Heap.c name.h name.c dataStructure/array.c dataStructure/array.h dataStructure/hash.c dataStructure/hash.h)