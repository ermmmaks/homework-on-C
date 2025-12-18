#include "double.h"
#include <math.h>
#include <stdio.h>

DoubleComponents doubleFormatCalc(double num)
{
    union data {
        double number_d;
        uint64_t number_i;
    } data;

    data.number_d = num;
    DoubleComponents res;

    uint64_t signBit = (data.number_i >> 63) & 0x1;
    res.sign = signBit ? '-' : '+';

    uint64_t expBits = (data.number_i >> 52) & 0x7FF;
    res.exponent = (int)expBits - 1023;

    uint64_t mantissaBits = (data.number_i) & 0xFFFFFFFFFFFFF;
    res.mantissa = 1.0 + (double)mantissaBits / pow(2.0, 52.0);

    return res;
}

void printComponents(DoubleComponents comp)
{
    printf("Result: %c%.52f*2^%d\n", comp.sign, comp.mantissa, comp.exponent);
}