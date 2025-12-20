#include <stdio.h>

/* математически:
# x^4 + x^3 + x^2 + x + 1 = (x^2 + x) * (x^2 + 1) + 1 =
= (a + x) * (a + 1) + 1 => 2 умножения */

int main()
{
    float x;
    printf("Введите знаение х: ");
    scanf("%f", &x);

    int square = x * x;
    int result = (square + x) * (square + 1) + 1;

    printf("Итоговая сумма: %f\n", result);

    return 0;
}