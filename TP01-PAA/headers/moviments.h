#ifndef MOVIMENTS_h
#define MOVIMENTS_h

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x, y, nessP, nessK, direction;
    char intersection;
} item;

typedef struct TypeNode *TypePointer;
typedef struct TypeNode
{
    item queueItem;
    TypePointer next;
} TypeNode;

typedef struct
{
    TypePointer front, back;
    int size;
} Queue;

void makeEmptyQueue(Queue *queue);
int emptyQueue(Queue queue);
void toQueue(item x, Queue *queue);
void dequeue(Queue *queue, item *itemQueue);
void printQueue(Queue *queue);
item newItem(int x, int y, int nessP, int nessK, int direction, char intersection);
int isInQueue(Queue *queue, int x, int y, int direction);
int isInQueueWhateverDirection(Queue *queue, int x, int y);
void backToLastNode(Queue *moviments, int *x, int *y);
void cleanQueue(Queue *moviments);

#endif