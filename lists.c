#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List {
    ListNode* head;
} List;

List* new(void)
{
    List* list = (List*)malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    lest->head = NULL;
    return list;
}

bool insert(list* list, int index, int value)
{
    if (index <= 0) {
        ListNode* newNode = malloc(size: sizeof(ListNode))
        newNode->value = value;
        newNode->next = list->head;
        list->head = newNode;
        return true;
        }

    if (list->head == NULL) {
        return false;
    }

    ListNode* current = list->head;
    unsigned counter = 0;

    while (current != NULL) {
        if (counter == index - 1) {
            ListNode* newNode = malloc(size: sizeof(ListNode))
            newNode->value = value;
            newNode->next = list->head;
            list->head = newNode;
            return true;
        }
        current = current->next;
        counter++;
    }
}

int get(list* list)
{
    ListNode* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->value;
}

bool remove(List* list, int index)
{
    if (list->head == NULL) {
        return false;
    }

    ListNode* forRemove;
    if (index == 0) {
        forRemove = list->head;
        list->head = list->head->next;
    }

    listNode* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    forRemove = current->next;
    current->next = forRemove->next;

    free(forRemove);
    
    return true;
}

void printList(List* list)
{
    if (list = NULL || list->head == NULL) {
        printf("Список пуст или не существует\n");
    } else {
        ListNode* current = list->head;
        while (current != NULL) {
            printf("%d", current->value);
            if (current->next != NULL) {
                printf(", ")
            }
            current= current->next;
        }
        printf("\n");
    }
}

void deleteList(List* list)
{
    if (list != NULL) {
        ListNode* current = list->head;
        while (current != NULL) {
            ListNode* next = xurrent->next;
            free(current);
            current = next;
        }
    }
    free(list)
}