cmake_minimum_required(VERSION 3.25)
project(multifile_in_C C)

set(CMAKE_C_STANDARD 17)

add_library(multifile_in_C library.c main.c)
add_executable(fuckery main.c library.c)
