#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "headers/test_fixed.h"
#include "headers/cmplx_arith_fixedpt.h"
#include "headers/fftc_fixedpt.h"

#define FLOAT2FIXED(x) ((int16_t)((x) * (1 << 8)))
#define FIXED2FLOAT(x) (((float)(x)) / (1 << 8))

int main() {
//    int i;
//    int N = 8;
//    int32_t x_in[N];
//    int32_t x_out[N];
//    for (i = 0; i < N; i++)
//    {
//        x_in[i] = create_CMPLX(FLOAT2FIXED(cos(i)), FLOAT2FIXED(sin(i)));
//
//    }
//    fftc_fixedp(x_in, x_out, N);
//    for (i = 0; i < N; i++)
//    {
//        printf("%f + %fi, ", fixed2float(GET_REAL(x_in[i])), fixed2float(GET_IMAG(x_in[i])));
//    }
//    printf("\n");
//    for (i = 0; i < N; i++)
//    {
//        printf("%f + %fi, ", fixed2float(GET_REAL(x_out[i])), fixed2float(GET_IMAG(x_out[i])));
//    }


    fft_tester(16, 1);
//    fft_tester(32, 100);
//    fft_tester(64, 100);
//    fft_tester(128, 100);
//    fft_tester(256, 100);
//    fft_tester(512, 100);
//    fft_tester(1024, 100);




    // Test cases ==================================
//    bfly_tester(128, 100);
    //==============================================




}