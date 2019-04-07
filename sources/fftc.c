//
// Created by Eric Lei on 4/6/19.
//

#include "../headers/fftc.h"
#include <stdio.h>

int reverseBits(int number)
{
    int reversed = 0;
    int lInd = FFT_LENGTH >> 1;
    static const int MultiplyDeBruijnBitPosition2[32] =
            {
                    0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
                    31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
            };
    int lIndPos = MultiplyDeBruijnBitPosition2[(unsigned)(lInd * 0x077CB531U) >> 27];
    int rInd = 1;
    int value = 0;

    while(lInd != 0) {
        value = ((rInd & number) != 0);
        reversed = (reversed & ~lInd) | (value << lIndPos);
        lInd >>= 1;
        lIndPos--;
        rInd <<= 1;
    }
    return reversed;
}

void sortBitReversed(float *input, float *output)
{
    int index, i;
    int Nover2 = FFT_LENGTH >> 1;
    output[0] = input[0];
    for (i = 1; i < FFT_LENGTH; i++)
    {
        index = reverseBits(i);
        output[i] = input[index];
    }
}

