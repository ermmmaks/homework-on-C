#include "double.h"
#include <stdio.h>

int main(void)
{
    double userNum;
    printf("Write a number: ");
    scanf("%lf", &userNum);

    DoubleComponents result = doubleFormatCalc(userNum);

    printComponents(result);

    return 0;
}