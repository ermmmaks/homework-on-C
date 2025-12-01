#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int precedence(char operator)
{
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    }

    return 0;
}

char* toPostfix(char* infix)
{
    Stack Stack = newStack();

    int j = 0;
    char* postfix[100];

    for (int i = 0; i < 100; i++) {
        char ch = infix[i];
        while (ch != '\0') {
            if (isdigit(ch)) {
                postfix[j++] = ch;
                postfix[j++] = ' ';
            } else if (ch == '(') {
                push(&Stack, ch);
            } else if (ch == ')') {
                while (!isEmpty(&Stack) && (top(&Stack) != '(')) {
                    postfix[j++] = pop(&Stack);
                    postfix[j++] = ' ';
                }
                pop(&Stack);
            } else if (ch == '-' || ch == '+' || ch == '*' || ch == '/') {
                while (!isEmpty(&Stack) && precedence(top(&Stack)) >= precedence(ch)) {
                    postfix[j++] = pop(&Stack);
                    postfix[j++] = ' ';
                }
                push(&Stack, ch);
            }
        }
    }

    while (!isEmpty(&Stack)) {
        postfix[j++] = pop(&newStack);
        postfix[j++] = ' ';

        postfix[j++] = '\0';
        deleteStack(&newStack);
    }

    return postfix*;
}

int main(void)
{
    char infix[100];

    printf("Введите инфиксное выражение: ");
    fgets(infix, 100, stdin);

    printf("Постфиксная запись: %s\n", toPostfix(infix));

    return 0;
}