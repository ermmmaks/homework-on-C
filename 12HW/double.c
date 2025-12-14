#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(void)
{
    union {
        double number_d;
        uint64_t number_i;
    } data;

    printf("Write a number: ");
    scanf("%lf", &data.number_d);
    
    char sign = signBit ? '-' : '+';

    uint64_t signBit = (data.number_i >> 63) & 0x1;

    uint64_t expBits = (data.number_i >> 52) & 0x7FF;

    uint64_t mantissaBits = (data.number_i) & 0xFFFFFFFFFFFFF;

    int exponent = (int)expBits - 1023;

    double normMantissa = 1.0 + (double)mantissaBits / pow(2.0, 52.0);

    printf("Result: %c%.52f*2^%d\n", sign, normMantissa, exponent);
    
    return 0;
}