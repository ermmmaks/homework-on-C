#include <stdio.h>

int fibonacci(int firstFib, int secondFib, int summEvenFib)
{
    int newFirstEvenFib;
    int newSecondFib;

    newFirstEvenFib = firstFib + 2 * secondFib;
    newSecondFib = newFirstEvenFib + firstFib + secondFib;

    if (newFirstEvenFib < 1000000) {
        summEvenFib += newFirstEvenFib;
        return fibonacci(newFirstEvenFib, newSecondFib, summEvenFib);
    }

    return summEvenFib;
}

int main(void)
{
    printf("%d\n", fibonacci(0, 1, 0));

    return 0;
}
