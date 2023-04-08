cmake_minimum_required(VERSION 3.22.1)
project(multifile_in_C C)

set(CMAKE_C_STANDARD 17)

add_library(multifile_in_C multifile.c main.c)
add_executable(fuckery main.c multifile.c)
