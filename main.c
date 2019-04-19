//#include "headers/fftc_fixedpt.h"
#include "headers/cmplx_arith_fixedpt.h"
#include <stdio.h>

/*
 * Print complex scalar or vector for debugging purposes.
 */
//void printCmplx(complex * vector, unsigned length)
//{
//    int i;
//    printf("real: ");
//    for (i = 0; i < length; i++)
//        printf("%f ", vector[i].real);
//    printf("\nimag: ");
//    for (i = 0; i < length; i++)
//        printf("%f ", vector[i].imag);
//    printf("\n");
//}

int main() {

    int32_t a = create_CMPLX(create_FP(3, 0), create_FP(1, 0));
    int32_t b = create_CMPLX(create_FP(5, 0), create_FP(1, 0));
    printf("%8d.%8d, %8d.%8d i\n",INT_PART(GET_REAL(a)), FRAC_PART(GET_REAL(a)), INT_PART(GET_IMAG(a)), FRAC_PART(GET_IMAG(a)));

    BFLY(&a, &b, 50, 1024);


    printf("%8d.%8d, %8d.%8d i\n",INT_PART(GET_REAL(a)), FRAC_PART(GET_REAL(a)), INT_PART(GET_IMAG(a)), FRAC_PART(GET_IMAG(a)));
    printf("%8d.%8d, %8d.%8d i\n",INT_PART(GET_REAL(b)), FRAC_PART(GET_REAL(b)), INT_PART(GET_IMAG(b)), FRAC_PART(GET_IMAG(b)));


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