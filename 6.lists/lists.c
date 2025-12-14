#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

List* createList(void)
{
    List* list = calloc(1, sizeof(struct List));
    list->head = NULL;
    return list;
}

bool insertList(List* list, int value)
{
    if (list == NULL) {
        return false;
    }

    ListNode* newNode = malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return false;
    }
    newNode->value = value;
    newNode->next = NULL;

    if ((list->head == NULL) || (value <= list->head->value)) {
        newNode->next = list->head;
        list->head = newNode;
        return true;
    }

    ListNode* current = list->head;
    while ((current->next != NULL) && (current->next->value < value)) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return true;
}

bool removeValue(List* list, int index)
{
    if (index < 0 || list->head == NULL) {
        return false;

    } else if (index == 0) {
        ListNode* rmNode = list->head;
        list->head = rmNode->next;
        free(rmNode);
        return true;
    } else {
        ListNode* current = list->head;
        int idx = 0;

        while (current->next != NULL) {
            if (idx == index - 1) {
                ListNode* rmNode = current->next;
                current->next = rmNode->next;
                free(rmNode);
                return true;
            }
            current = current->next;
            idx++;
        }
    }
    return false;
}

int get(List* list, int index, bool* status)
{
    if (list->head == NULL || index < 0 || list == NULL) {
        if (status != NULL) {
            *status = false;
        }
        return -1;
    }
    ListNode* current = list->head;
    int idx = 0;
    while (current != NULL) {
        if (index == idx) {
            return current->value;
        }
        current = current->next;
        idx++;
    }
    if (status != NULL) {
        *status = false;
    }
    return -1;
}

void printList(List* list)
{
    if (list == NULL) {
        printf("List is NULL\n");
    } else {
        ListNode* current = list->head;
        while (current != NULL) {
            printf("%d", current->value);
            current = current->next;
        }
        printf("\n");
    }
    return;
}

bool deleteList(List* list)
{
    if (list == NULL) {
        return false;
    }
    while (list->head != NULL) {
        removeValue(list, 0);
    }
    free(list);
    return true;
}