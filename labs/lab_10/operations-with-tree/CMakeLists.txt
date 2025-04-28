cmake_minimum_required(VERSION 3.29)
project(lab_10 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_10 main.c
               friends.c
               friends.h
               headers/binary_tree.h
               headers/constants.h
               main.h
               )
