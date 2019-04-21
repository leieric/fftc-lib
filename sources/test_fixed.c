//
// Created by Eric Lei on 4/20/19.
//

#include "../headers/test_fixed.h"
#include "../headers/fftc_fixedpt.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>

#define FIXED2FLOAT(x) (((float)(x)) / (1 << 8))

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

void bfly_tester(unsigned N, unsigned num_test) {
// Test and write to file
    int32_t* in_a = (int32_t*) malloc(num_test * sizeof(int32_t));
    int32_t* in_b = (int32_t*) malloc(num_test * sizeof(int32_t));
    int32_t* out_a = (int32_t*) malloc(num_test * sizeof(int32_t));
    int32_t* out_b = (int32_t*) malloc(num_test * sizeof(int32_t));
    assert(in_a != NULL);
    assert(in_b != NULL);
    assert(out_a != NULL);
    assert(out_b != NULL);
    FILE *fp;
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    int k, i;
    for (k = 0; k < 4; k++) {
        char dir[100];
        sprintf(dir, "../data/testBfly_%d_%d.csv", k, N);
        fp = fopen(dir, "w");
        test_bfly(in_a, in_b, out_a, out_b, k, N, num_test);
        fprintf(fp, "%d, %d\n", k, N);
        for (i = 0; i < num_test; i++) {
            fprintf(fp, "%f, %f, %f, %f, %f, %f, %f, %f\n", fixed2float(GET_REAL(in_a[i])),
                    fixed2float(GET_IMAG(in_a[i])),
                    fixed2float(GET_REAL(in_b[i])), fixed2float(GET_IMAG(in_b[i])), fixed2float(GET_REAL(out_a[i])),
                    fixed2float(GET_IMAG(out_a[i])), fixed2float(GET_REAL(out_b[i])), fixed2float(GET_IMAG(out_b[i])));
        }
        fclose(fp);
    }
}

void fft_tester(unsigned N, unsigned num_test)
{
    int32_t* in = (int32_t*) malloc(N * sizeof(int32_t));
    int32_t* out = (int32_t*) malloc(N * sizeof(int32_t));
    assert(in != NULL);
    assert(out != NULL);
    int i, j;

    FILE *fp;
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    char dir[100];
    sprintf(dir, "../data/fftTest_%d.csv", N);
    fp = fopen(dir, "w");
    fprintf(fp, "%d\n", N);

    for(j = 0; j < num_test; j++) {
        for (i = 0; i < N; i++) {
            in[i] = rand() - 2147483647 / 4;
        }

        fftc_fixedp(in, out, N);

        for (i = 0; i < N; i++) {
            fprintf(fp, "%f, ", fixed2float(GET_REAL(in[i])));
        }
        fprintf(fp, "%\n");
        for (i = 0; i < N; i++) {
            fprintf(fp, "%f, ", fixed2float(GET_IMAG(in[i])));
        }
        fprintf(fp, "%\n");
        for (i = 0; i < N; i++) {
            fprintf(fp, "%f, ", fixed2float(GET_REAL(out[i])));
        }
        fprintf(fp, "%\n");
        for (i = 0; i < N; i++) {
            fprintf(fp, "%f, ", fixed2float(GET_IMAG(out[i])));
        }
        fprintf(fp, "%\n");
    }
    fclose(fp);

}

