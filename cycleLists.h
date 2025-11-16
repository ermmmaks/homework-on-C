#pragma once
#include <stdbool.h>

List* new(void);
bool insert(list* list, int index int value);
int get(list* list);
bool remove(List* list, int index);
void printList(List* list);
void deleteList(List* list);
