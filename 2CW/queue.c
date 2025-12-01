#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

Queue* newQueue()
{
    Queue* q = (Queue*)malloc(sixeof(Queue));
    q->f = newList();
    q->r = newList();
    return q;
}

bool queueIsEmpty(Queue* q)
{
    return isEmpty(q->f);
}

Queue* normalize(Queue* q)
{
    if (isEmpty(q->f)) {
        Queue* newQueuePtr = newQueue();
        deleteList(newQueuePtr->f);
        deleteList(newQueuePtr->r);

        newQueuePtr->f = reverse(q->r);
        newQueuePtr->r = newList();

        deleteList(q->f);
        deleteList(q->r);

        return newQueuePtr;
    }
    return q;
}

Queue* enqueue(Queue* q, int value)
{
    Queue* newQueuePtr = (Queue*)malloc(sizeof(Queue));
    newQueuePtr->r = insert(value, q->r);
    newQueuePtr->f = q->f;

    return normalize(newQueuePtr);
}

Queue* dequeue(Queue* q, int* value)
{
    ListNode* head = q->f->head;
    *value = head->value;

    Queue* newQueuePtr = newQueue();
    deleteList(newQueuePtr->f);
    deleteList(newQueuePtr->r);

    newQueuePtr->f = newList();
    newQueuePtr->f->head = head->next;

    newQueuePtr->r = q->r;

    return normalize(newQueuePtr);
}

void deleteQueue(Queue* q)
{
    deleteList(q->f);
    deleteList(q->r);
    free(q);
}

void printQueue(Queue* q)
{
    printf("f = ");
    printlist(q->f);
    printf("r = ");
    printList(q->r);
    printf("\n");
}
