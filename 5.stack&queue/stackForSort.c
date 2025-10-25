#include "sortStation.h"
#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    char digit;
    struct StackNode* next;
};
struct Stack {
    struct StackNode* head;
};

char head(Stack *stack)
{
    if (!isEmpty(stack)) {
        return stack->
    }
}

Stack* newStack(void)
{
    Stack* stack = calloc(1, sizeof(*stack));
    return stack;
}

void push(Stack* stack, char digit)
{
    struct StackNode* node = (struct StackNode*)malloc(sizeof(struct StackNode));

    node->digit = digit;
    node->next = stack->head;
    stack->head = node;
}
char pop(Stack* stack)
{
    if (stack->head == NULL) {
        return '\0';
    }
    struct StackNode* oldNode = stack->head;
    char res = oldNode->digit;
    stack->head = oldNode->next;

    free(oldNode);
    return res;
}

bool isEmpty(Stack* stack)
{
    return stack->head == NULL;
}

void deleteStack(Stack* stack)
{   
    while (!isEmpty(stack)){
        pop(stack);
    }
    free(stack);
}

//(*p).x =: p->x