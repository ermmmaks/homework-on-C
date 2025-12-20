#pragma once
#include <stdbool.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List {
    ListNode* tail; //указатель на хвост. на голову будет tail->next
} List;

List* createNew(void);

bool insert(List* list, int index, int value);

bool pop(List* list, int index);

void removeNext(List* list, ListNode* curr);

void printList(List* list);

void deleteList(List* list);
