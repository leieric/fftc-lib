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
    int i;
    int N = 8;
    int32_t x_in[N];
    int32_t x_out[N];
    for (i = 0; i < N; i++)
    {
        x_in[i] = create_CMPLX(FLOAT2FIXED(sin(i)), create_FP(1,0));
    }
    fftc_fixedp(x_in, x_out, N);
    for (i = 0; i < N; i++)
    {
        printf("%f + %fi, ", FIXED2FLOAT(GET_REAL(x_in[i])), FIXED2FLOAT(GET_IMAG(x_in[i])));
    }
    printf("\n");
    for (i = 0; i < N; i++)
    {
        printf("%f + %fi, ", FIXED2FLOAT(GET_REAL(x_out[i])), FIXED2FLOAT(GET_IMAG(x_out[i])));
    }



    // Test cases ==================================
//    bfly_tester(128, 100);
    //==============================================




}