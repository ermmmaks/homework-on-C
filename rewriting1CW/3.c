#include "3.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int value;
    struct ListNode* next;
};

struct List {
    struct ListNode* head;
};

List* createList(void)
{
    List* list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    return list;
}

bool insertList(List* list, int index, int value)
{
    if (list == NULL) {
        return false;
    }

    ListNode* newNode = malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return false;
    }
    newNode->value = value;
    
    newNode->next = list->head;
    list->head = newNode;

    return true;
}

int pop(List* list, int index) 
{
    if (index < 0 || list->head == NULL) {
        return -1;
    }

    int popValue;

    if (index == 0) {
        ListNode* popNode = list->head;
        list->head = popNode->next;
        popValue = popNode->value;
        free(popNode);
        return true;
    }

    ListNode* current = list->head;
    int idx = 0;
    while ((current != NULL) && (current->next != NULL)) {
        if (idx == index - 1) {
            ListNode* popNode = current->next;
            current->next = popNode->next;
            popValue = popNode->value;
            free(popNode);
            return true;
        }
        current = current->next;
        idx++;
    }
    return -1;
}

int get(List* list, int index)
{
    if (list->head == NULL || index < 0 || list == NULL) {
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
    return -1;
}

void printList(List* list)
{
    if (list == NULL) {
        printf("List is NULL\n");
        return;
    }

    ListNode* current = list->head;
    while (current != NULL) {
        printf("%d", current->value);
        current = current->next;
    }
    printf("\n");
}

bool deleteList(List* list)
{
    if (list == NULL) {
        return false;
    }
    while (list->head != NULL) {
        pop(list, 0);
    }
    free(list);
    return true;
}

List* reverseList(List* list)
{
    if (list == NULL || list->head == NULL || list->head->next == NULL) {
        return list;
    }

    ListNode* prev = NULL;
    ListNode* current = list->head;
    ListNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list->head = prev;

    return list;
}

bool isEqual(List* list1, List* list2)
{
    if (list1 == NULL || list2 == NULL) {
        return list1 == list2;
    }
    ListNode* curr1 = list1->head;
    ListNode* curr2 = list2->head;

    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->value != curr2->value) {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return curr1 == NULL && curr2 == NULL;
}
