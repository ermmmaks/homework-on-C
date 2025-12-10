#include <stdio.h>
#include <string.h>

int fib(int firstFib, int secondFib)
{
    return firstFib + secondFib;
}

int main(void)
{
    int firstFib = 0;
    int secondFib = 1;

    int userNum = 0;
    scanf("%d", &userNum);
    char strFib[userNum + 50];
    strcpy(strFib, "01");

    int nextFib = 0;
    char nextStrFib[20];

    while (strlen(strFib) <= userNum) {
        nextFib = fib(firstFib, secondFib);
        firstFib = secondFib;
        secondFib = nextFib;
        sprintf(nextStrFib, "%d", nextFib);
        strcat(strFib, nextStrFib);
    }
    printf("%c\n", strFib[userNum - 1]);

    return 0;
}