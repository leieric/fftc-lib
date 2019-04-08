//
// Created by Eric Lei on 4/6/19.
//

#include "../headers/fftc.h"

static const unsigned BitPosition[32] =
        {0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
         31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9};

unsigned reverseBits(unsigned number)
{
    unsigned reversed = 0;
    unsigned lInd = FFT_LENGTH >> 1;

    unsigned lIndPos = BitPosition[(unsigned)(lInd * 0x077CB531U) >> 27];
    unsigned rInd = 1;
    unsigned value = 0;

    while(lInd != 0) {
        value = ((rInd & number) != 0);
        reversed = (reversed & ~lInd) | (value << lIndPos);
        lInd >>= 1;
        lIndPos--;
        rInd <<= 1;
    }
    return reversed;
}

void sortBitReversed(complex *input, complex *output)
{
    int index, i;
    output[0] = input[0];
    for (i = 1; i < FFT_LENGTH; i++)
    {
        index = reverseBits(i);
        output[i] = input[index];
    }
}

void singleBfly(complex *a, complex *b, unsigned k)
{
    complex a_old;
    a_old = *a;
    *a = CMPLX_ADD(*a, CMPLX_MULT(*b, twiddle(FFT_LENGTH, k)));
    *b = CMPLX_SUB(a_old, CMPLX_MULT(*b, twiddle(FFT_LENGTH, k)));
}

void fftStage(complex *input_vec, unsigned num_points)
{
    int i, j;
    unsigned Nover2 = num_points/2;
    unsigned k_factor = FFT_LENGTH / num_points;
    for(i = 0; i < FFT_LENGTH; i += num_points)
    {
        //perform computation
        for(j = 0; j < Nover2; j++)
        {
            singleBfly(input_vec+j+i, input_vec+j+i+Nover2, j*k_factor);
        }
    }
}

void fftc(complex *input_vec, complex *output_vec)
{
    // Sort the input vector in reverse bit order
    sortBitReversed(input_vec, output_vec);

    // Compute FFT in feedfoward manner
    int i;
    unsigned num_stages = BitPosition[(unsigned)(FFT_LENGTH * 0x077CB531U) >> 27];
    unsigned num_points = 2;
    for (i = 0; i < num_stages; i++)
    {
        fftStage(output_vec, num_points);
        num_points *= 2;
    }
}



