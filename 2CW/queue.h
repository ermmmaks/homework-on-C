#include "list.h"

typedef struct Queue {
    List* f;
    List* r;
}

Queue* newQueue();
bool queueIsEmpty(Queue* q);
Queue* enqueue(Queue* q, int value);
Queue* dequeue(Queue* q, int* value);
void printQueue(Queue* q);
void deleteQueue(Queue* q);