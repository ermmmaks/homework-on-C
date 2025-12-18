#include <stdio.h>

int incompleteQuotient(int dividend, int divider)
{ /*функция "неполноеЧастное" на вход получает делимое и делитель,
  а выдает значение частного или ошибку при делении на "0"*/
    if (divider == 0) {
        printf("Делить на ноль нельзя!\n");
        return -1;
    }

    int quotient = 0;
    int remainder = dividend;
    int sign = 1; // отслеживаю знак чисел и по нему определяю знак результата

    if (dividend < 0) {
        sign *= -1;
        remainder *= -1;
    }

    if (divider < 0) {
        sign *= -1;
        divider *= -1;
    }

    while (remainder >= divider) {
        remainder -= divider;
        quotient++;
    }

    return sign * quotient;
}

int main()
{ // считываю данные пользователя и вызываю функцию неполногоЧастного
    int userDividend = 0;
    int userDivider = 1;

    printf("Введите делимое: ");
    scanf("%d", &userDividend);

    printf("Введите делитель: ");
    scanf("%d", &userDivider);

    int result = incompleteQuotient(userDividend, userDivider);

    if (result != -1)
        printf("Неполное частное = %d\n", result);

    else
        printf("Введены некорректные данные!\n");

    return 0;
}