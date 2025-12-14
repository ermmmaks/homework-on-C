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

void toPostfix(char* infix, char* postfix)
{
    Stack* stack = newStack();

    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            postfix[j++] = ch;
            postfix[j++] = ' ';
        } else if (ch == '(') {
            push(stack, ch);
        } else if (ch == ')') {
            while (!isEmpty(stack) && (top(stack) != '(')) {
                postfix[j++] = pop(stack);
                postfix[j++] = ' ';
            }
            pop(stack);
        } else if (ch == '-' || ch == '+' || ch == '*' || ch == '/') {
            while (!isEmpty(stack) && precedence(top(stack)) >= precedence(ch)) {
                postfix[j++] = pop(stack);
                postfix[j++] = ' ';
            }
            push(stack, ch);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
        postfix[j++] = ' ';        
    }

    postfix[j] = '\0';
    deleteStack(&stack);
}

int main(void)
{
    char initial[] = "(1 + 1) * 2";
    char result[20];

    toPostfix(initial, result);

    printf("Постфиксная запись: %s\n", result);

    return 0;
}