#include "binaryRep.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool testToBinaryRep(void)
{
    bool result = true;

    printf("=== Testing toBin function ===\n");

    Bin32 bin5 = toBin(5);
    Bin32 bin2048 = toBin(2048);
    Bin32 bin666111444 = toBin(666111444);

    if (compareBinWithStr(bin5, "00000000000000000000000000000101") &&
        compareBinWithStr(bin2048, "00000000000000000000100000000000") &&
        compareBinWithStr(bin666111444, "00100111101101000000110111010100 ")) {
        printf("= toBin positive - Success!!! :D\n");
    } else {
        printf("= toBin positive - Fail... ;(\n");
        result = false;
    }


    Bin32 binMinus10 = toBin(-10);
    Bin32 binMinus1024 = toBin(-1024);
    Bin32 binMinus777000777 = toBin(-777000777);

    if (compareBinWithStr(binMinus10, "11111111111111111111111111110110") &&
        compareBinWithStr(binMinus1024, "11111111111111111111110000000000") &&
        compareBinWithStr(binMinus777000777, "11010001101011111110100010110111")) {
        printf("= toBin negative - Success!!! :D\n");
    } else {
        printf("= toBin negative - Fail... ;(\n");
        result = false;
    }

    printf("=== Testing binSum function ===\n");
    printf("(Only if toBin is correct)\n");

    Bin32 sum5AndMinus10 = binSum(bin5, binMinus10);
    Bin32 sumPositive = binSum(bin2048, binMinus1024);
    Bin32 sumNegative = binSum(bin666111444, binMinus777000777);

    if (compareBinWithStr(sum5AndMinus10, "11111111111111111111111111111011") &&
        compareBinWithStr(sumPositive, "00000000000000000000010000000000") &&
        compareBinWithStr(sumNegative, "11111001011000111111011010001011")) {
        printf("= binSum - Success!!! :D\n");
    } else {
        printf("= binSum - Fail... ;(\n");
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
    printf("=== Testing extreme cases ===");

    Bin32 binOver = toBin(2147483648); //2^31
    Bin32 sumOver = binSum(binOver, binOver);

    if (sumOver.overflow) {
        printf("= overflow detecting - Success!!! :D\n");
    } else {
        printf("= overflow detecting - Fail... ;(\n");
        result = false;
    }

    Bin32 bin1 = toBin(1);
    Bin32 binMinus1 = toBin(-1);
    Bin32 bin0 = toBin(0);

    Bin32 sum1AndMinus1 = binSum(bin1, binMinus1);
    Bin32 sum1And0 = binSum(bin1, bin0);
    Bin32 sum0And0 = binSum(bin0, bin0);

    if (compareBinWithStr(sum1AndMinus1, "00000000000000000000000000000000") &&
        compareBinWithStr(sum1And0, "00000000000000000000000000000001") &&
        compareBinWithStr(sum0And0, "00000000000000000000000000000000")) {
        printf("= sum -1, 0 and 1 - Success!!! :D\n");
    } else {
        printf("= sum -1, 0 and 1 - Fail... ;(\n");
        result = false;
    }

    Bin32 binBig = toBin(2147483647); // 2^31 - 1
    Bin32 binMinusBig = toBin(-2147483648); // -2^31

    Bin32 sumBigAndMinus1 = binSum(binBig, binMinus1);
    Bin32 sumMinusBigAnd1 = binSum(binMinusBig, bin1);

    if (compareBinWithStr(sumBigAndMinus1, "01111111111111111111111111111110") &&
        compareBinWithStr(sumMinusBigAnd1, "10000000000000000000000000000001")) {
        printf("= near overflow - Success!!! :D\n");
    } else {
        printf("= near overflow - Fail... ;(\n");
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