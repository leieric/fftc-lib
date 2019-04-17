//
// Created by Eric Lei on 4/17/19.
//

#ifndef FFTC_LIB_FFTC_FIXEDPT_H
#define FFTC_LIB_FFTC_FIXEDPT_H

#include <stdlib.h>
#include <stdio.h>
#include "cmplx_arith_fixedpt.h"

/*
 * One stage of the FFT.
 * Parametrized by FFT_LENGTH and num_points.
 * Ex: 1st stage in FFT will do FFT_LENGTH/2 2-point
 * DFT's, so num_points will be 2. Subsequent stages
 * will combine results of 1st stage, but still uses
 * the butterfly operation.
 */
void fftStage_fixedp(int32_t *input_vec, unsigned num_points, unsigned N);

/*
 * Calculates the FFT_LENGTH FFT.
 */
void fftc_fixedp(int32_t *input_vec, int32_t *output_vec, unsigned N);

#endif //FFTC_LIB_FFTC_FIXEDPT_H
