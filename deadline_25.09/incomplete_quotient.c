#include <stdio.h>

int incomplete_quotient(int dividend, int divider)
{
    if (divider==0)
    {
        printf("Делить на ноль нельзя!\n");
        return -1;
    }
    int quotient = 0;
    int remainder = dividend;

    int sign = 1;
    if (dividend<0)
    {
        sign *= -1;
        dividend *= -1;
    }
    if (divider<0)
    {
        sign *= -1;
        divider *= -1;
    }
    
    while (remainder >= divider)
    {
        remainder -= divider;
        quotient++;
    }
    return sign * quotient;
}

int main()
{
    int user_dividend, user_divider;
    printf("Введите делимое: ");
    scanf("%d", &user_dividend);
    printf("Введите делитель: ");
    scanf("%d", &user_divider);
    
    int result = incomplete_quotient(user_dividend,user_divider);
    if (result != -1)
    {
        printf("Неполное частное = %d\n", result);
    }
    return 0;
}
