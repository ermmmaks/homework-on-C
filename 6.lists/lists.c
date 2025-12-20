#include "lists.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct SortedList {
    struct ListNode* head;
} SortedList;

SortedList* createList(void)
{
    SortedList* list = calloc(1, sizeof(struct SortedList));
    list->head = NULL;
    return list;
}

bool isEmpty(SortedList* list)
{
    if (list == NULL) {
        return true;
    }
    return (list->head == NULL);
}

bool insertList(SortedList* list, int value)
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

bool removeValue(SortedList* list, int num)
{
    if (list->head == NULL || list == NULL) {
        return false;
    }

    ListNode* curr = list->head;
    ListNode* prev = NULL;
    while (curr != NULL && curr->value != num) {
        if (curr->value > num) {
            return false;
        }
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        return false;
    }

    if (prev == NULL) {
        list->head = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr);
    return true;
}

/* status отвечает за успех/неудачу операции (есть защита от нулевого указателя)
если список не существует, пуст или индекс отрицательный - даем статус false
ищем ноду по индексу. Если нашли - возвращаем значение
если нет и индекс больше размеров списка, то даем статус false
(при неудаче неважно что return'ить. Это сделано, чтобы можно было и -1, к примеру, получить из списка без конфликта)
*/

int get(SortedList* list, int index, bool* status)
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

void printList(SortedList* list)
{
    if (list == NULL) {
        printf("List is NULL\n");
    } else {
        printf("[");
        ListNode* current = list->head;
        while (current->next != NULL) {
            printf("%d, ", current->value);
            current = current->next;
        }
        printf("%d]\n", current->value);
    }
    return;
}

bool deleteList(SortedList* list)
{
    if (list == NULL) {
        return false;
    }

    ListNode* curr = list->head;
    ListNode* nextNode;

    while (curr != NULL) {
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
    free(list);
    return true;
}