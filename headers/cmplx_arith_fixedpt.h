
#ifndef FFTC_LIB_CMPLX_ARITH_FIXEDPT_H
#define FFTC_LIB_CMPLX_ARITH_FIXEDPT_H

#include <stdint.h>

static inline int16_t create_FP(int8_t int_part, int8_t frac_part)
{
    return (int16_t) ((int_part << 8) + frac_part);
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

//TODO
static inline int32_t TWIDDLE_FIXEDP(int N, int k)
{
    int16_t real = 0;
    int16_t imag = 0;
    return (int32_t) ((real << 16) + imag);
}


#endif //FFTC_LIB_CMPLX_ARITH_FIXEDPT_H
