#include <stdio.h>

bool incompleteQuotient(int dividend, int divider, int* quotient)
{ /*функция "неполноеЧастное" на вход получает делимое и делитель,
  а выдает значение частного или ошибку при делении на "0"*/
    if (divider == 0) {
        printf("Делить на ноль нельзя!\n");
        return false;
    }

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
        (*quotient)++;
    }
    (*quotient) *= sign;

    return true;
}

int main()
{ // считываю данные пользователя и вызываю функцию неполногоЧастного
    int userDividend = 0;
    int userDivider = 1;
    int quotient = 0;

    printf("Введите делимое: ");
    scanf("%d", &userDividend);

    printf("Введите делитель: ");
    scanf("%d", &userDivider);

    if (incompleteQuotient(userDividend, userDivider, &quotient)) {

        printf("Неполное частное = %d\n", quotient);
    }
    else
        printf("Введены некорректные данные!\n");

    return 0;
}