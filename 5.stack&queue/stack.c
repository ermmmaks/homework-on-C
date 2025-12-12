#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack* newStack(void)
{
    Stack* stack = malloc(sizeof(Stack));

    if (stack == NULL) {
        printf("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    stack->head = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack* stack, char value)
{
    StackNode* node = malloc(sizeof(StackNode));

    node->value = value;
    node->next = stack->head;
    stack->size++;
    stack->head = node;
}

char pop(Stack* stack)
{
    if (stack->head == NULL) {
        return '\0';
    }
    struct StackNode* oldNode = stack->head;
    char res = oldNode->value;
    stack->head = oldNode->next;
    stack->size--;

    free(oldNode);

    return res;
}

bool isEmpty(Stack* stack)
{
    return stack->head == NULL;
}

void deleteStack(Stack** stackAddress)
{
    if (stackAddress == NULL || *stackAddress == NULL) {
        return;
    }
    Stack* stack = *stackAddress;

    while (!isEmpty(stack)) {
        pop(stack);
    }

    free(stack);
    *stackAddress = NULL;
}

char top(Stack* stack)
{
    if (!isEmpty(stack)) {
        return stack->head->value;
    }
    return '\0';
}