#pragma once
#include <stdbool.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List {
    struct ListNode* head;
} List;

List* createList(void);
bool insertList(List* list, int index, int value);
int pop(List* list, int index);
int get(List* list, int index);
void printList(List* list);
bool deleteList(List* list);
List* reverseList(List* list);
bool isEqual(List* list1, List* list2);