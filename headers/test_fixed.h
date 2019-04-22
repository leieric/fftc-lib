//
// Created by Eric Lei on 4/20/19.
//

#ifndef FFTC_LIB_TEST_FIXED_H
#define FFTC_LIB_TEST_FIXED_H

#include "cmplx_arith_fixedpt.h"

void test_bfly(int32_t * in_a, int32_t *in_b, int32_t * out_a, int32_t *out_b, unsigned k, unsigned N, unsigned num_test);

float fixed2float(int16_t fixed);

void bfly_tester(unsigned N, unsigned num_test);

void fft_tester(unsigned N, unsigned num_test);

void fft_test_data(unsigned N, unsigned num_test);




#endif //FFTC_LIB_TEST_FIXED_H
