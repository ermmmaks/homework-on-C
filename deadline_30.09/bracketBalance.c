#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool checkBalance(const char* text)
{
    // На вход принимает неизменяемую строку, выдает значение true или false
    int balance = 0; // Завожу счетчик, в котором "(" прибавляет 1, а ")" - убавляет

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '(') {
            balance++;
        } else if (text[i] == ')') {
            balance--;
            if (balance < 0) /*Если кол-во ")" превысило "(", то баланс
            отрицательный => нарушено правило вложенности скобок*/
                return false;
        }
    }

    return balance == 0;
}

int main()
{
    char str[1000];

    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);

    if (checkBalance(str))
        printf("Balance saved\n");
    else
        printf("Balance isnt saved\n");

    return 0;
}