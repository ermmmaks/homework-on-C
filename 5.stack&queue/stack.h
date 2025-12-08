#pragma once
#include <stdbool.h>

typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* head;
    int size;
} Stack;

Stack newStack(void);
void push(Stack* stack, int value);
char pop(Stack* stack);
bool isEmpty(Stack* stack);
void deleteStack(Stack* stack);
char top(Stack* stack);