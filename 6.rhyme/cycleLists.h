#pragma once
#include <stdbool.h>

typedef struct ListNode ListNode;

typedef struct CycleList CycleList;

CycleList* createNew(void);

bool insert(CycleList* list, int index, int value);

bool pop(CycleList* list, int index);

void removeNext(CycleList* list, ListNode* curr);

void printList(CycleList* list);

void deleteList(CycleList* list);
