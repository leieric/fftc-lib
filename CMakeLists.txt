cmake_minimum_required(VERSION 3.6)
project(fftc_lib)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c sources/test_fixed.c headers/test_fixed.h headers/twiddles.h sources/fftc_fixedpt.c headers/fftc_fixedpt.h)
add_executable(fftc_lib ${SOURCE_FILES})