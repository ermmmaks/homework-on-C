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
    Stack stack = newStack();

    int j = 0;
    char postfix[100];

    for (int i = 0; i < 100; i++) {
        char ch = infix[i];
        while (ch != '\0') {
            if (isdigit(ch)) {
                postfix[j++] = ch;
                postfix[j++] = ' ';
            } else if (ch == '(') {
                push(&stack, ch);
            } else if (ch == ')') {
                while (!isEmpty(&stack) && (top(&stack) != '(')) {
                    postfix[j++] = pop(&stack);
                    postfix[j++] = ' ';
                }
                pop(&stack);
            } else if (ch == '-' || ch == '+' || ch == '*' || ch == '/') {
                while (!isEmpty(&stack) && precedence(top(&stack)) >= precedence(ch)) {
                    postfix[j++] = pop(&stack);
                    postfix[j++] = ' ';
                }
                push(&stack, ch);
            }
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
        postfix[j++] = ' ';

        postfix[j++] = '\0';
        deleteStack(&stack);
    }

    return postfix;
}

int main(void)
{
    char infix[100];

    printf("Введите инфиксное выражение: ");
    fgets(infix, 100, stdin);

    printf("Постфиксная запись: %s\n", toPostfix(infix));

    return 0;
}