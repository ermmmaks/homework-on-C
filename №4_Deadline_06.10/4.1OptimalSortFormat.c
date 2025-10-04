#include <stdio.h>

extern int sortNumbers(int* array, int count);

int main()
{
    int numbers[100];
    int countOfNum = 0;
    int userNum;
    
    while (scanf("%d", &userNum) == 1 && countOfNum < 100) {
        numbers[countOfNum++] = userNum;
    }
    
    int movedCount = sortNumbers(numbers, countOfNum);
    
    for (int i = 0; i < countOfNum; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    printf("Count of moved elements: %d\n", movedCount);
    
    return 0;
}