//#include "headers/fftc_fixedpt.h"
#include "headers/cmplx_arith_fixedpt.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "headers/test_fixed.h"


float fixed2float(int16_t fixed)
{
    int i;
    float output = 0;
    for (i = -8; i < 7; i++)
    {
        output += (fixed & 0x1)*powf(2, i);
        fixed >>= 1;
    }
    output += (fixed & 0x1)*powf(-2, i);
    return output;
}

void printCmplx(int32_t val)
{
    printf("%f + %f i\n", fixed2float(GET_REAL(val)), fixed2float(GET_IMAG(val)));
}

void test_bfly(int32_t * in_a, int32_t *in_b, int32_t * out_a, int32_t *out_b, unsigned k, unsigned N, unsigned num_test)
{
    int i;
    for (i = 0; i < num_test; i++)
    {
        in_a[i] = rand() - 2147483647/2;
        in_b[i] = rand() - 2147483647/2;
        out_a[i] = in_a[i];
        out_b[i] = in_b[i];
    }
    for (i = 0; i < num_test; i++)
    {
        BFLY(&out_a[i], &out_b[i], k, N);
    }
}


int main() {
    FILE *fp;
    fp = fopen("../data/test.txt","w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    int i;
    int num_test = 100;
    int32_t* in_a = (int32_t*) malloc(num_test * sizeof(int32_t));
    int32_t* in_b = (int32_t*) malloc(num_test * sizeof(int32_t));
    int32_t* out_a = (int32_t*) malloc(num_test * sizeof(int32_t));
    int32_t* out_b = (int32_t*) malloc(num_test * sizeof(int32_t));
    assert(in_a != NULL);
    assert(in_b != NULL);
    assert(out_a != NULL);
    assert(out_b != NULL);

    // Test and write to file
    test_bfly(in_a, in_b, out_a, out_b, 3, 128, num_test);
    fprintf(fp, "%d, %d\n", 3, 128);
    for (i = 0; i < num_test; i++)
    {
        fprintf(fp, "%f, %f, %f, %f, %f, %f, %f, %f\n", fixed2float(GET_REAL(in_a[i])), fixed2float(GET_IMAG(in_a[i])),
                fixed2float(GET_REAL(in_b[i])), fixed2float(GET_IMAG(in_b[i])), fixed2float(GET_REAL(out_a[i])),
                fixed2float(GET_IMAG(out_a[i])), fixed2float(GET_REAL(out_b[i])), fixed2float(GET_IMAG(out_b[i])));
    }

    free(in_a);
    free(in_b);
    free(out_a);
    free(out_b);
    fclose(fp);







    int32_t a = create_CMPLX(create_FP(3, 0), create_FP(1, 0));
    int32_t b = create_CMPLX(create_FP(5, 0), create_FP(1, 0));

    printCmplx(a);
    printCmplx(b);

    BFLY(&a, &b, 50, 128);
    printCmplx(a);
    printCmplx(b);


}