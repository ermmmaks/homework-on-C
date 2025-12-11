#include "1.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* numbers = (int*)malloc(1000 * sizeof(int));
    int count = 0;

    int userNum = 0;
    scanf("%d", &userNum);

    while (userNum != 0) {
        numbers[count] = userNum;
        count++;
        scanf("%d", &userNum);
        if (count == 1000) {
            printf("Max elements!\n");
            break;
        }
    }

    bubbleSort(numbers, count);

    int countCurr = 1;

    for (int i = 0; i < count; i++) {
        if (numbers[i] == numbers[i + 1]) {
            countCurr++;
        } else {
            printf("Element %d finded %d times\n", numbers[i], countCurr);
            countCurr = 1;
        }
    }

    free(numbers);

    return 0;
}