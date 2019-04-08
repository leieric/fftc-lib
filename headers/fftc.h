//
// Created by Eric Lei on 4/6/19.
//

#ifndef FFTC_LIB_FFTC_H
#define FFTC_LIB_FFTC_H

#include <stdlib.h>
#include <stdio.h>
#include "cmplx_arith.h"

#define FFT_LENGTH 8    // length of the FFT, assume power of 2

/*
 * Helper function for sortBitReversed()
 */
unsigned reverseBits(unsigned number);

/*
 * Sorts the input array into bit-reversed order.
 * Assumes input array is of length FFT_LENGTH.
 * Very bad O(N^2) complexity. But just need to run once.
 */
void sortBitReversed(complex *input, complex *output); //CHANGE TO INT

/*
 * Single butterfly computation.
 * Output put into given complex structs.
 */
void singleBfly(complex *a, complex *b, unsigned k);


/*
 * One stage of the FFT.
 * Parametrized by FFT_LENGTH and num_points.
 * Ex: 1st stage in FFT will do FFT_LENGTH/2 2-point
 * DFT's, so num_points will be 2. Subsequent stages
 * will combine results of 1st stage, but still uses
 * the butterfly operation.
 */
void fftStage(complex *input_vec, unsigned num_points);

/*
 * Calculates the FFT_LENGTH FFT.
 */
void fftc(complex *input_vec, complex *output_vec);

#endif //FFTC_LIB_FFTC_H
