#include "optSort.h"
#include <stdlib.h>
#include <string.h>

int bubbleSort(int* numbers, int count)
{
    int* unsorted = calloc(count, sizeof(int));

    memcpy(unsorted, numbers, count * sizeof(int));

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    int countOfMoved = 0;

    for (int i = 0; i < count; i++) {
        if (numbers[i] != unsorted[i]) {
            countOfMoved++;
        }
    }
    free(unsorted);
    return countOfMoved;
}