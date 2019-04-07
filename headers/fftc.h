//
// Created by Eric Lei on 4/6/19.
//

#ifndef FFTC_LIB_FFTC_H
#define FFTC_LIB_FFTC_H

#include <stdlib.h>
#include <stdio.h>
#include "cmplx_arith.h"

#define FFT_LENGTH 8       // length of the FFT

/*
 * Helper function for sortBitReversed()
 */
int reverseBits(int number);

/*
 * Sorts the input array into bit-reversed order.
 * Assumes input array is of length FFT_LENGTH.
 */
void sortBitReversed(float *input, float *output); //CHANGE TO INT



#endif //FFTC_LIB_FFTC_H
