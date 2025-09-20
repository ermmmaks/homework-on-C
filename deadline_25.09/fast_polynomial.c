#include <stdio.h>

/* математически:
# x^4 + x^3 + x^2 + x + 1 = x^2*(x + 1) + x*(x + 1) + 1 =
= (x+1)*(x^2+x) + 1 => 2 умножения */

int main()
{
    float x;
    printf("Введите знаение х: ");
    scanf("%f", &x);

    float square = x * x;
    float result = (x+1)*(square+x)+1;
    printf("Итоговая сумма: %f\n", result);
    
    return 0;
}