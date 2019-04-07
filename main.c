#include <stdio.h>
#include "headers/fftc.h"

int main() {
    int i;
    float test[FFT_LENGTH];
    for (i = 0; i < FFT_LENGTH; i++)
    {
        test[i] =  (float) i;
    }
    float testout[FFT_LENGTH];
    sortBitReversed(test, testout);
    for (i = 0; i < FFT_LENGTH; i++)
    {
        printf("%f ", test[i]);
    }
    printf("\n");
    for (i = 0; i < FFT_LENGTH; i++)
    {
        printf("%f ", testout[i]);
    }
}