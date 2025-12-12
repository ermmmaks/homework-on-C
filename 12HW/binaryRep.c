#include "binaryRep.h"
#include <stdbool,h>
#include <stdio.h>
#include <stdlib.h>

char* toBin(int num)
{
    char* bits = calloc(32, sizeof(char));
    for (int i = 0; i < 32; i++) {
        bits[31 - i] = (num >> i) & 1;
    }
    return bits;
}

char* binSum(char* bin1, char* bin2)
{
    char* res = calloc(32, sizeof(char));
    char d = 0;
    char curr = 0;
    for (int i = 31; i >= 0; i--) {
        curr = 0;
        curr += bin2[i];
        curr += bin1[i];
        curr += d;
        if (curr == 1) {
            res[i] = 1;
            d = 0;
        } else if (curr == 2) {
            d = 1;
        } else if (curr == 3) {
            d = 1;
            res[i] = 2;
        }
    }

    return res;
}

char* toint(int sum)
{
    int result = 0;

    if (sum[0] == 0) {
        for (int i = 31; i >= 0; i--) {
            if (sum[i]) {
                res += 1 << 31 - i;
            }
        }
        return res;
    } else {
        for (int i = 31; i >= 0; i--) {
            if (!sum[i]) {
                res += 1 << 31 - i;
            }
        }
        res += 1;
        return -res;
    }
}

void print(char* sum, bool full)
{
    bool signedBit = full;
    for (int i = 0; i <= 31; i++) {
        if (!signedBit) {
            signedBit = (sum[i] == 1);
        }
        if (signedBit) {
            printf("%d", sum[i]);
        }
    }
    if (!signedBit) {
        printf("0");
    }
    printf("\n");
}