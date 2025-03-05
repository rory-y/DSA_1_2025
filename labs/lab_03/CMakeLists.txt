cmake_minimum_required(VERSION 3.29)
project(lab_03 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_03 main.c
               library.h
               libtestLib.a
               Students/student_functions.h
               Students/student_functions.c
               )
# Link the static library
target_link_libraries(lab_03 ${PROJECT_SOURCE_DIR}/libtestLib.a)

target_link_libraries(lab_03 m) # this is used to explicitly link the math library (named 'm') with the project

