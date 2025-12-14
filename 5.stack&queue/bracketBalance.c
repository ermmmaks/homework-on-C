#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isPair(char c1, char c2)
{
    if (c1 == '(' && c2 == ')') {
        return true;
    } else if (c1 == '[' && c2 == ']') {
        return true;
    } else if (c1 == '{' && c2 == '}') {
        return true;
    }
    return false;
}

bool balance(const char* text)
{
    Stack* stack = newStack();

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (c == '(' || c == '{' || c == '[') {
            push(stack, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(stack)) {
                deleteStack(&stack);
                return false; // проверка количества скобок
            }
            char topChar = pop(stack);
            if (!isPair(topChar, c)) {
                deleteStack(&stack);
                return false; // проверка вложенности скобок
            }
        }
    }

    bool balance = isEmpty(stack);
    deleteStack(&stack);
    return balance;
}

int main(void)
{
    char userStr[100];
    printf("Write your string: ");
    fgets(userStr, sizeof(userStr), stdin);

    if (balance(userStr)) {
        printf("Balance saved\n");
    } else {
        printf("Balance isnt saved\n");
    }

    return 0;
}
