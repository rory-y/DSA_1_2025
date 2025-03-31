cmake_minimum_required(VERSION 3.29)
project(lab_05 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_05 src/main.c
               src/main.h
               src/glass.c
               src/glass.h
               src/glasses_circular_queue.c
               src/glasses_circular_queue.h
               )
