#pragma once
#include <stdbool.h>
#include <stdint.h>

typedef struct Bin32 {
    bool bits[32];
} Bin32;

Bin32 toBin(int num);
Bin32 binSum(Bin32 bin1, Bin32 bin2);
int32_t toInt(Bin32 sum);
void print(Bin32 sum, bool fullOrNot);