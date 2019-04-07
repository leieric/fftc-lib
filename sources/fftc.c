//
// Created by Eric Lei on 4/6/19.
//

#include "../headers/fftc.h"

unsigned reverseBits(unsigned number)
{
    unsigned reversed = 0;
    unsigned lInd = FFT_LENGTH >> 1;
    static const unsigned MultiplyDeBruijnBitPosition2[32] =
            {
                    0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
                    31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
            };
    unsigned lIndPos = MultiplyDeBruijnBitPosition2[(unsigned)(lInd * 0x077CB531U) >> 27];
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
    complex *a_old;
    a_old = a;
    *a = CMPLX_ADD(*a, CMPLX_MULT(*b, twiddle(FFT_LENGTH, k)));
    *b = CMPLX_SUB(*a_old, CMPLX_MULT(*b, twiddle(FFT_LENGTH, k)));
}

void fftStage(complex *input_vec, unsigned num_points)
{
    int i, j;
    int Nover2 = num_points/2;
    for(i = 0; i < FFT_LENGTH; i += num_points)
    {
        //perform computation
        for(j = i; j < Nover2 + i; j++)
        {
            singleBfly(input_vec + j, input_vec + j + Nover2, 3);
        }
    }
}



