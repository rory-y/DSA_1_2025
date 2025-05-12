cmake_minimum_required(VERSION 3.29)
project(lab_12 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_12 main.c
               headers/main.h
               headers/book.h
               headers/binary_tree.h
               sources/book.c
               sources/binary_tree.c
               )
