#include "cycleLists.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct CycleList {
    ListNode* tail; // указатель на хвост. на голову будет tail->next
} CycleList;

CycleList* createNew()
{
    CycleList* list = (CycleList*)calloc(1, sizeof(List));
    return list;
}

bool insert(CycleList* list, int index, int num)
{
    if (index < 0 || !list) {
        return false;
    }

    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

    newNode->value = num;

    if (list->tail == NULL) {
        newNode->next = newNode;
        list->tail = newNode;
        return true;
    }

    if (index == 0) {
        newNode->next = list->tail->next;
        list->tail->next = newNode;
        return true;
    }

    ListNode* curr = list->tail->next;
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
        if (curr == list->tail->next) {
            free(newNode);
            return false;
        }
    }
    newNode->next = curr->next;
    curr->next = newNode;

    if (curr == list->tail) {
        list->tail = newNode;
    }

    return true;
}

bool pop(CycleList* list, int index)
{
    if (index < 0 || !list->tail || !list) {
        return false;
    }

    ListNode* head = list->tail->next;

    if (index == 0) {
        if (list->tail == head) {
            list->tail = NULL;
        } else {
            list->tail->next = head->next;
        }
        free(head);
        return true;
    }

    ListNode* curr = head;
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
        if (curr->next == head) {
            return false;
        }
    }

    ListNode* target = curr->next;
    if (target == head) {
        return false;
    }

    curr->next = target->next;
    if (target == list->tail) {
        list->tail = curr;
    }
    free(target);

    return true;
}

void removeNext(CycleList* list, ListNode* curr)
{
    if (!list || !list->tail) {
        return;
    }
    ListNode* target = curr->next;
    if (target == curr) {
        list->tail == NULL;
    } else {
        curr->next = target->next;
        if (target == list->tail) {
            list->tail = curr;
        }
    }
    free(target);
}

void printList(CycleList* list)
{
    if (!list || !list->tail) {
        printf("List is empty!\n");
        return;
    }

    ListNode* head = list->tail->next;
    ListNode* curr = head;
    do {
        printf("%d ", curr->value);
        curr = curr->next;
    } while (curr != head);
    printf("\n");
}

void deleteList(CycleList* list)
{
    while (list->tail != NULL) {
        pop(list, 0);
    }
    free(list);
}