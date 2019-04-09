#include "headers/fftc.h"

/*
 * Print complex scalar or vector for debugging purposes.
 */
void printCmplx(complex * vector, unsigned length)
{
    int i;
    printf("real: ");
    for (i = 0; i < length; i++)
        printf("%f ", vector[i].real);
    printf("\nimag: ");
    for (i = 0; i < length; i++)
        printf("%f ", vector[i].imag);
    printf("\n");
}

int main() {
    int i;
    int N = 8; //should match FFT_LENGTH
    complex test[N];
    for (i = 0; i < N; i++)
    {
        test[i].real = sin(i);
        test[i].imag = 0.0;
    }
    printCmplx(test, N);
    complex testout[N];
    //--------------------------------
    fftc(&test, &testout);
    //--------------------------------
    printCmplx(testout, N);
//    printCmplx(testout, N);
}