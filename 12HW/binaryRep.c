#include "binaryRep.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
        bool bitOf1 = bin1.bits[i];
        bool bitOf2 = bin2.bits[i];

        res.bits[i] = bitOf1 ^ bitOf2 ^ carry;
        carry = (bitOf1 && bitOf2) || (carry && (bitOf1 ^ bitOf2));
    }

    return res;
}

int32_t toInt(Bin32 sum)
{
    int32_t res = 0;

    if (sum.bits[0] == 0) {
        for (int i = 0; i < 32; i++) {
            if (sum.bits[i] == 1) {
                res |= (int32_t)1 << (32 - 1 - i);
            }
        }
    } else {
        uint32_t invert = 0;

        for (int i = 0; i < 32; i++) {
            if (sum.bits[i] == 0) {
                invert |= (uint32_t)1 << (32 - 1 - i);
            }
        }
        int32_t absolut_unsigned = (int32_t)invert + 1;

        res = -absolut_unsigned;
    }

    return res;
}

void print(Bin32 sum, bool fullOrNot)
{
    bool full = fullOrNot;
    for (int i = 0; i < 32; i++) {
        if (!full && sum.bits[i] == 1) {
            full = true;
        }
        if (full) {
            printf("%d", sum.bits[i] ? 1 : 0);
        }
    }

    if (!full) {
        printf("0");
    }

    printf("\n");
}