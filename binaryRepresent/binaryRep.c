#include "binaryRep.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

Bin32 toBin(int32_t num)
{
    Bin32 res;
    for (int i = 0; i < 32; i++) {
        res.bits[32 - 1 - i] = (num >> i) & 1;
    }

    return res;
}

Bin32 binSum(Bin32 bin1, Bin32 bin2)
{
    Bin32 res;
    bool carry = false;

    for (int i = 32 - 1; i >= 0; i--) {
        int sum = bin1.bits[i] + bin2.bits[i] + carry;
        res.bits[i] = sum % 2;
        carry = sum / 2;
    }

    return res;
}

int32_t toInt(Bin32 sum)
{
    int32_t res = 0;

    if (sum.bits[0] == 0) {
        for (int i = 0; i < 32; i++) {
            res = (res << 1) | sum.bits[i];
        }

    } else {
        Bin32 invert;

        for (int i = 0; i < 32; i++) {
            invert.bits[i] = !sum.bits[i];
        }
        Bin32 one = toBin(1);

        Bin32 absolut_unsigned = binSum(invert, one);
        for (int i = 0; i < 32; i++) {
            res = (res << 1) | absolut_unsigned.bits[i];
        }

        res = -res;
    }

    return res;
}

void printFull(Bin32 num)
{
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