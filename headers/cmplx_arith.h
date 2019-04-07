//
// Created by Eric Lei on 4/6/19.
//

#ifndef FFTC_LIB_CMPLX_ARITH_H
#define FFTC_LIB_CMPLX_ARITH_H

#include <math.h> //FOR FLOATING POINT ONLY, REMOVE LATER

typedef struct {
    float real; //CHANGE TO INT
    float imag; //CHANGE TO INT
} complex;

static inline complex CMPLX_MULT(complex *z1, complex *z2)
{
    return (complex) {z1->real * z2->real - z1->imag * z2->imag,
                      z1->real * z2->imag + z2->real * z1->imag};
}

static inline complex CMPLX_ADD(complex *z1, complex *z2)
{
    return (complex) {z1->real + z2->real,
                      z1->imag + z2->imag};
}

static inline complex CMPLX_SUB(complex *z1, complex *z2)
{
    return (complex) {z1->real - z2->real,
                      z1->imag - z2->imag};
}

// CHANGE TO INT
static inline complex CMPLX_EXP(float theta)
{
    return (complex) {cos(theta),
                      sin(theta)};
}


#endif //FFTC_LIB_CMPLX_ARITH_H
