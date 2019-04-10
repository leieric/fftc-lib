#include "headers/fftc.h"
#include "headers/cmplx_arith_fixedpt.h"

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
    int16_t val1 = create_FP(128, 255);
    int16_t val2 = 4 << 8;
    int16_t out  = FP_MULT(val1, val2);
    printf("%d\n", FRAC_PART(val1));


//    int i;
//    int N = 8; //should match FFT_LENGTH
//    complex test[N];
//    for (i = 0; i < N; i++)
//    {
//        test[i].real = sin(i);
//        test[i].imag = 0.0;
//    }
//    printCmplx(test, N);
//    complex testout[N];
//    //--------------------------------
//    fftc(&test, &testout);
//    //--------------------------------
//    printCmplx(testout, N);
////    printCmplx(testout, N);
}