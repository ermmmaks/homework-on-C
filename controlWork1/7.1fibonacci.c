#include <stdio.h>

int summEvenFib = 0;

int fibonacci(int firstFib, int secondFib)
{
    int newFirstEvenFib;
    int newSecondFib;

    newFirstEvenFib = firstFib + 2 * secondFib;
    newSecondFib = newFirstEvenFib + firstFib + secondFib;
    summEvenFib += newFirstEvenFib;

    if (newFirstEvenFib < 1000000) {
        return fibonacci(newFirstEvenFib, newSecondFib);
    }

    return summEvenFib;
}

int main(void)
{
    printf("%d", fibonacci(0, 1), "\n");

    return 0;
}
