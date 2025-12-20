#include <stdio.h>

int main()
{
    int countTickets = 0;
    int sums[28] = { 0 };

    for (int a = 0; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            for (int c = 0; c <= 9; c++) {
                int sumNum = a + b + c;
                sums[sumNum]++;
            }
        }
    }

    for (int countSumNum = 0; countSumNum <= 27; countSumNum++) {
        countTickets += sums[countSumNum] * sums[countSumNum];
    }

    printf("Count of lucky tickets: %d\n", countTickets);

    return 0;
}