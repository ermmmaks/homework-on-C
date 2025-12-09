#include "optSort.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* numbers = calloc(100, sizeof(int));
    int countOfNum = 0;
    char userSym = 0;

    while (userSym != '\n') {
        int inputNum = 0;
        int f = scanf("%d", &inputNum);
        if (f == 1) {
            numbers[countOfNum++] = inputNum;
        }

        userSym = getchar();
        if (userSym == '\n') {
            break;
        }
    }
    printf("Count of moved elements: %d\n", bubbleSort(numbers, countOfNum));

    free(numbers);
    return 0;
}