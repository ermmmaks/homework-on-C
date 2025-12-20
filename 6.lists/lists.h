#pragma once
#include <stdbool.h>

typedef struct ListNode ListNode;

typedef struct SortedList SortedList;

// создает список с одной нодой-головой

SortedList* createList(void);

//два условия пустоты - не существование и указатель на голову == NULL

bool isEmpty(SortedList* list);

// вставка значения в сортированный список

bool insertList(SortedList* list, int value);

// удаление элемента по значению

bool removeValue(SortedList* list, int value);

// возвращает элемент по индексу

int get(SortedList* list, int index, bool* status);

// вывод итеративно каждого элемента

void printList(SortedList* list);

// поочередно с головы удаляет элементы

bool deleteList(SortedList* list);
