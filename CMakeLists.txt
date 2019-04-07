cmake_minimum_required(VERSION 3.8)
project(fftc_lib)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c sources/fftc.c headers/fftc.h)
add_executable(fftc_lib ${SOURCE_FILES})