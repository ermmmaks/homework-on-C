#pragma once
#include <stdbool.h>

typedef struct ListNode ListNode;

typedef struct CycleList CycleList;

// выделение памяти для списка

CycleList* createNew(void);

// добавление элемента в список по индексу

bool insert(CycleList* list, int index, int value);

// удаление элемента по индексу

bool pop(CycleList* list, int index);

// удаление следующего элемента

void removeNext(CycleList* list, ListNode* curr);

// вывод списка

void printList(CycleList* list);

// удаление списка

void deleteList(CycleList* list);

// трюк с считалочкой

int trick(int n, int m);