#include <stdint.h>

typedef struct DoubleComponents {
    char sign;
    int exponent;
    double mantissa;
} DoubleComponents;

DoubleComponents doubleFormatCalc(double num);

void printComponents(DoubleComponents comp);