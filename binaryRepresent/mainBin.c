#include "binaryRep.h"
#include <stdio.h>

int main(void)
{
    int32_t num1 = 0;
    int32_t num2 = 0;

    printf("Write the first num: ");
    scanf("%d", &num1);
    printf("Write the second num: ");
    scanf("%d", &num2);

    Bin32 bin1 = toBin(num1);
    Bin32 bin2 = toBin(num2);

    printf("First num in binary sys: ");
    printFull(bin1);
    printf("Second num in binary sys: ");
    printCompact(bin2);

    Bin32 resBin = binSum(bin1, bin2);
    printf("Summ nums in binary sys: ");
    printFull(resBin);

    int32_t resInt = toInt(resBin);
    printf("Summ in int sys: %d\n", resInt);

    return 0;
}