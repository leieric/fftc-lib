
#ifndef FFTC_LIB_CMPLX_ARITH_FIXEDPT_H
#define FFTC_LIB_CMPLX_ARITH_FIXEDPT_H

#include <stdint.h>
#include "twiddles.h"

static inline int16_t create_FP(int8_t int_part, int8_t frac_part)
{
    return (int16_t) ((int_part << 8) + frac_part);
}

static inline int32_t create_CMPLX(int16_t real, int16_t imag)
{
    return (int32_t) ((real << 16) + imag);
}

static inline int16_t GET_REAL(int32_t val)
{
    return (int16_t) (val >> 16);
}

static inline int16_t GET_IMAG(int32_t val)
{
    return (int16_t) (val & 0xffff);
}


static inline int8_t INT_PART(int16_t val)
{
    return (int8_t) (val >> 8);
}

static inline int8_t FRAC_PART(int16_t val)
{
    return (int8_t) (val & 0xff);
}

static inline int16_t MULT_FIXEDP(int16_t val1, int16_t val2)
{
    int32_t temp = val1*val2;
    return (int16_t) ((temp >> 8) & 0xffff);
}

static inline int32_t CMULT_FIXEDP(int32_t z1, int32_t z2)
{
    int16_t real = MULT_FIXEDP(GET_REAL(z1), GET_REAL(z2)) - MULT_FIXEDP(GET_IMAG(z1), GET_IMAG(z2));
    int16_t imag = MULT_FIXEDP(GET_REAL(z1), GET_IMAG(z2)) + MULT_FIXEDP(GET_IMAG(z1), GET_REAL(z2));
    return (int32_t) ((real << 16) + imag);
}

static inline int32_t CADD_FIXEDP(int32_t z1, int32_t z2)
{
    int16_t real = GET_REAL(z1) + GET_REAL(z2);
    int16_t imag = GET_IMAG(z1) + GET_IMAG(z2);
    return (int32_t) ((real << 16) + imag);
}

static inline int32_t CSUB_FIXEDP(int32_t z1, int32_t z2)
{
    int16_t real = GET_REAL(z1) - GET_REAL(z2);
    int16_t imag = GET_IMAG(z1) - GET_IMAG(z2);
    return (int32_t) ((real << 16) + imag);
}

static inline void BFLY_FIXEDP(int32_t *a, int32_t *b, unsigned k, unsigned N)
{
    int32_t a_old = *a;
    *a = CADD_FIXEDP(*a, CMULT_FIXEDP(*b, twiddles[(1024 - (k*1024)/N) % 1024])); //should compile into shifts
    *b = CSUB_FIXEDP(a_old, CMULT_FIXEDP(*b, twiddles[(1024 - (k*1024)/N) % 1024]));
}

static inline void BFLY(int32_t *a, int32_t *b, unsigned k, unsigned N)
{
    int32_t real_a, imag_a, real_b, imag_b, twidprod_real, twidprod_imag;
    int32_t twiddle =  twiddles[(k*1024)/N];
    twidprod_real = GET_REAL(*b) * GET_REAL(twiddle) - GET_IMAG(*b) * GET_IMAG(twiddle);
    twidprod_imag = GET_REAL(*b) * GET_IMAG(twiddle) + GET_IMAG(*b) * GET_REAL(twiddle);
    real_a = twidprod_real + ((GET_REAL(*a) & 0xffffffff) << 8);
    imag_a = twidprod_imag + ((GET_IMAG(*a) & 0xffffffff) << 8);

    //switch
    real_b = (((GET_REAL(*a) & 0xffffffff) << 8) - twidprod_real);
    imag_b = (((GET_IMAG(*a) & 0xffffffff) << 8) - twidprod_imag);

    *a =  ((real_a << 8) & 0xffff0000) + ((imag_a >> 8) & 0xffff); //truncate and pack Re, Im parts of a and write to A
    *b =  ((real_b << 8) & 0xffff0000) + ((imag_b >> 8) & 0xffff);

}


#endif //FFTC_LIB_CMPLX_ARITH_FIXEDPT_H
