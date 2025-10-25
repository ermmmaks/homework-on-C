#include "sortStation.h"
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
    Stack* Stack;
    Stack* newStack(&Stack)

    int j = 0;
    char* postfix[100];

    for (int i = 0; i < 100; i++) {
        char ch = infix[i];
        while (ch != '\0') {
            if (isdigit(ch)) {
                postfix[j++] = ch;
                postfix[j++] = ' '
            } else if (ch == '(') {
                push(&newStack, ch);
            } else if (ch == ')') {
                while (!isEmpty(&newStack) && (head(&newStack) != '(')) {
                    postfix[j++] = pop(&newStack);
                    postfix[j++] = ' ';
                }
                pop(&newStack);
            } else if (ch == '-' || ch == '+' || ch == '*' || ch == '/') {
                while (!isEmpty(&newStack) && precedence(head(&newStack)) >= precedence(ch)) {
                    postfix[j++] = pop(&newStack);
                    postfix[j++] = ' ';
                }
                push(&newStack, ch);
            }
        }
    }
    
    while (!isEmpty(&newStack)) {
        postfix[j++] = pop(&newStack);
        postfix[j++] = ' ';

        postfix[j++] = '\0';
        deleteStack(&newStack);
    }

    return postfix;
}

int main(void)
{
    char infix[100];

    printf("Введите инфиксное выражение: ");
    fgets(infix, 100, stdin);

    char* postfix = toPostfix(infix);

    printf("Постфиксная запись: %s\n", postfix)

    return 0;
}