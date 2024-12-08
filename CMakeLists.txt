cmake_minimum_required(VERSION 3.29)
project(Praktikum4 C)

set(CMAKE_C_STANDARD 90)

add_executable(Praktikum4 main.c
        newton.c)

add_compile_options(Praktikum4 -std=c89 -Werror -Wall -Wextra -pedantic -Wconversion)


