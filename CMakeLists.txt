cmake_minimum_required(VERSION 3.24)
project(RNG1 C)

set(CMAKE_C_STANDARD 99)

add_executable(RNG1 main.c gb_flip.c Headers/gb_flip.h)
