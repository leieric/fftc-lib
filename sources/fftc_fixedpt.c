
#include "../headers/fftc_fixedpt.h"

static const unsigned BitPosition[32] =
        {0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
         31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9};

unsigned reverseBits(unsigned number, unsigned N)
{
    unsigned reversed = 0;
    unsigned lInd = N >> 1;

    unsigned lIndPos = BitPosition[(unsigned)(lInd * 0x077CB531U) >> 27];
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

void sortBitReversed(int32_t *input, int32_t *output, unsigned N)
{
    int index, i;
    output[0] = input[0];
    for (i = 1; i < N; i++)
    {
        index = reverseBits(i, N);
        output[i] = input[index];
    }
}

void fftStage_fixedp(int32_t *input_vec, unsigned num_points, unsigned N)
{
    int i, j;
    unsigned Nover2 = num_points/2;
    unsigned k_factor = N / num_points;
    for(i = 0; i < N; i += num_points)
    {
        //perform computation
        for(j = 0; j < Nover2; j++)
        {
            BFLY(input_vec+j+i, input_vec+j+i+Nover2, j*k_factor, N);
        }
    }
}

void fftc_fixedp(int32_t *input_vec, int32_t *output_vec, unsigned N)
{
    // Sort the input vector in reverse bit order
    sortBitReversed(input_vec, output_vec, N);

    // Compute FFT in feedfoward manner
    int i;
    unsigned num_stages = BitPosition[(unsigned)(N * 0x077CB531U) >> 27];
    unsigned num_points = 2;
    for (i = 0; i < num_stages; i++)
    {
        fftStage_fixedp(output_vec, num_points, N);
        num_points *= 2;
    }
}

