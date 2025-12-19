#include "binaryRep.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Bin32 toBin(int32_t num)
{
    Bin32 res;
    res.overflow = false;

    for (int i = 0; i < 32; i++) {
        res.bits[32 - 1 - i] = (num >> i) & 1;
    }

    return res;
}

Bin32 binSum(Bin32 bin1, Bin32 bin2)
{
    Bin32 res;
    res.overflow = false;
    bool carry = false;
    bool carryLast = false;

    for (int i = 32 - 1; i >= 0; i--) {
        bool A = bin1.bits[i];
        bool B = bin2.bits[i];

        if (i == 0) {
            carryLast = carry;
        }

        res.bits[i] = A ^ B ^ carry;
        carry = (A & B) | (carry & (A ^ B));
    }

    if (carry!= carryLast) {
        res.overflow = true;
    }

    return res;
}

/* копирует поразрядно каждый бит в res, кроме знакового.
если число было отрицательным, вычитает 2^31 степени,
что вернет знак на место
*/

int32_t toInt(Bin32 num)
{
    int32_t res = 0;

    for (int i = 1; i < 32; i++) {
        res = (res << 1) | num.bits[i];
    }

    if (num.bits[0] == 1) {
        res |= (1 << 31);
    }

    return res;
}

void printFull(Bin32 num)
{
    if (num.overflow) {
        printf("OVERFLOOOOOWWW\n");
        return;
    }

    for (int i = 0; i < 32; i++) {
        printf("%d", num.bits[i]);
        if ((i + 1) % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

void printCompact(Bin32 num)
{
    if (num.overflow) {
        printf("OVERFLOOOOOWWW\n");
        return;
    }

    int i = 0;
    bool status = false;

    for (int i = 0; i < 32; i++) {
        if (num.bits[i] != 0 || status) {
            status = true;
            printf("%d", num.bits[i]);
            if ((i + 1) % 8 == 0) {
                printf(" ");
            }
        }
    }
    if (!status) {
        printf("0");
    }
    printf("\n");
}

bool compareBinWithStr(Bin32 num1, char* num2)
{
    for (int i = 0; i < 32; i++) {
        char currentBit = num1.bits[i] ? '1' : '0';
        if (num2[i] != currentBit) {
            return false;
        }
    }
    return true;
}