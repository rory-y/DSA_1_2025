cmake_minimum_required(VERSION 3.29)
project(treap_project C)

set(CMAKE_C_STANDARD 23)

add_executable(treap_project
               headers/main.h
               headers/treap.h
               sources/treap.c
               main.c
               )
