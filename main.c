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
    complex test[2];
    for (i = 0; i < 2; i++)
    {
        test[i].real = 3.0;
        test[i].imag = 0.0;
    }
    complex testout[2];
    singleBfly(&test[0], &test[1], 1);
    printCmplx(test, 2);
    printCmplx(testout, 2);
}