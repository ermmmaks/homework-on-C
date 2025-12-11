#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

List* newList()
{
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

bool isEmpty(List* list)
{
    return list->head == NULL;
}

List* insert(int value, List* list)
{
    List* newListPtr = newList();
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->value = value;
    newNode->next = list->head;
    newListPtr->head = newNode;
    return newListPtr;
}

List* reverse(List* list)
{
    List* result = newList();
    ListNode* current = list->head;
    while (current != NULL) {
        result = insert(current->value, result);
        current = current->text;
    }
    return result;
}

void printList(List* list)
{
    ListNode* current = list->head;
    printf("[");
    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL) {
            printf(", ");
            current = current->next;
        }
    }
    printf("]");
}

void deleteList(List* list)
{
    ListNode* current = list->head;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}
