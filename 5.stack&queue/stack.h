#pragma once
#include <stdbool.h>

typedef struct StackNode {
    char value;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* head;
    int size;
} Stack;

Stack* newStack(void);
void push(Stack* stack, char value);
char pop(Stack* stack);
bool isEmpty(Stack* stack);
void deleteStack(Stack** stack);
char top(Stack* stack);