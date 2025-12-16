#include "binaryRep.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool testToBinaryRep(void)
{
    bool result = true;

    printf("=== Testing toBin function ===\n");

    Bin32 bin5 = toBin(5);
    Bin32 binMinus10 = toBin(-10);

    if (compareBinWithStr(bin5, "00000000000000000000000000000101")) {
        printf("= toBin(5) - Success!!! :D\n");
    } else {
        printf("= toBin(5) - Fail... ;(\n");
        result = false;
    }

    if (compareBinWithStr(binMinus10, "11111111111111111111111111110110")) {
        printf("= toBin(-10) - Success!!! :D\n");
    } else {
        printf("= toBin(-10) - Fail... ;(\n");
        result = false;
    }

    printf("=== Testing binSum function ===\n");
    printf("(Only if toBin is correct)\n");

    Bin32 sum5AndMinus10 = binSum(bin5, binMinus10);

    if (compareBinWithStr(sum5AndMinus10, "11111111111111111111111111111011")) {
        printf("= binSum(bin5, binMinus10) - Success!!! :D\n");
    } else {
        printf("= binSum(bin5, binMinus10) - Fail... ;(\n");
        result = false;
    }

    printf("=== Testing toInt function ===\n");

    int32_t intMinusSum = toInt(sum5AndMinus10);
    int32_t intBin5 = toInt(bin5);

    if (intMinusSum == -5) {
        printf("= toInt(sum5AndMinus10) - Success!!! :D\n");
    } else {
        printf("= toInt(sum5AndMinus10) - Fail... ;(\n");
        result = false;
    }

    if (intBin5 == 5) {
        printf("= toInt(bin5) - Success!!! :D\n");
    } else {
        printf("= toInt(bin5) - Fail... ;(\n");
        result = false;
    }

    return result;
}

int main()
{
    if (testToBinaryRep()) {
        printf("=== Good job! ===\n");
    } else {
        printf("=== Try again :* ===\n");
    }

    return 0;
}