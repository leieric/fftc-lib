cmake_minimum_required(VERSION 3.8)
project(fftc_lib)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c sources/fftc.c headers/fftc.h headers/cmplx_arith.h headers/cmplx_arith_fixedpt.h headers/fftc_fixedpt.h sources/fftc_fixedpt.c)
add_executable(fftc_lib ${SOURCE_FILES})