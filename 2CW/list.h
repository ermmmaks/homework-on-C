#pragma once
#include <stdbool.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List {
    struct ListNode* head;
} List;

List* newList();
bool insert(int value, List* list);
void printList(List* list);
bool deleteList(List* list);