cmake_minimum_required(VERSION 3.29)
project(lab_04 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_04 main.c
               int_stack/int_stack_functions.c
               int_stack/int_stack_functions.h
               char_stack/char_stack_functions.c
               char_stack/char_stack_functions.h
               )

