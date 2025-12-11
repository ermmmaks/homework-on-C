#include "2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(char* numbers, int count)
{
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

long long smallestNum(long long num)
{
    if (num < 0) {
        printf("Num must be natural");
        return -1;
    }
    if (num == 0) {
        return 0;
    }

    char strNum[20];
    sprintf(strNum, "%lld", num);
    int len = strlen(strNum);

    bubbleSort(strNum, len);

    if (strNum[0] == '0') {
        for (int i = 1; i < len; i++) {
            if (strNum[i] != '0') {
                char temp = strNum[0];
                strNum[0] = strNum[i];
                strNum[i] = temp;
                break;
            }
        }
    }

    return atoll(strNum);
}