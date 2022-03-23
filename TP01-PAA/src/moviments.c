#include "../headers/moviments.h"

void makeEmptyQueue(Queue *queue)
{
  queue->front = (TypePointer)malloc(sizeof(TypeNode));
  queue->back = queue->front;
  queue->front->next = NULL;
}

int emptyQueue(Queue queue)
{
  return (queue.front == queue.back);
}

void toQueue(item x, Queue *queue)
{
  queue->back->next = (TypePointer)malloc(sizeof(TypeNode));
  queue->back = queue->back->next;
  queue->back->queueItem = x;
  queue->back->next = NULL;
}

void dequeue(Queue *queue, item *itemQueue)
{
  TypePointer q;
  if (emptyQueue(*queue))
  {
    printf("Erro fila esta vazia\n");
    return;
  }
  q = queue->front;
  queue->front = queue->front->next;
  *itemQueue = queue->front->queueItem;
  free(q);
}

void printQueue(Queue *queue)
{
  TypePointer Aux;
  Aux = queue->front->next;
  while (Aux != NULL)
  {
    printf("x: %d, y: %d, P: %d,K: %d, direction: %d, intersection: %c\n", Aux->queueItem.x, Aux->queueItem.y, Aux->queueItem.nessP, Aux->queueItem.nessK, Aux->queueItem.direction, Aux->queueItem.intersection);
    Aux = Aux->next;
  }
}

item newItem(int x, int y, int nessP, int nessK, int direction, char intersection)
{
  item newItemQueue;
  newItemQueue.x = x;
  newItemQueue.y = y;
  newItemQueue.nessP = nessP;
  newItemQueue.nessK = nessK;
  newItemQueue.direction = direction;
  newItemQueue.intersection = intersection;

  return newItemQueue;
}

int isInQueue(Queue *queue, int x, int y, int direction)
{
  TypePointer Aux;
  int find = 0;
  Aux = queue->front->next;
  while (Aux != NULL)
  {
    if (Aux->queueItem.x == x && Aux->queueItem.y == y && Aux->queueItem.direction == direction)
    {
      find = 1;
    }
    Aux = Aux->next;
  }

  return find;
}

int isInQueueWhateverDirection(Queue *queue, int x, int y)
{
  TypePointer Aux;
  int find = 0;
  Aux = queue->front->next;
  while (Aux != NULL)
  {
    if (Aux->queueItem.x == x && Aux->queueItem.y == y)
    {
      find = 1;
    }
    Aux = Aux->next;
  }

  return find;
}

void backToLastNode(Queue *moviments, int *x, int *y)
{
  TypePointer Aux;
  Aux = moviments->front->next;
  while (Aux->next->next != NULL)
  {
    Aux = Aux->next;
  }

  dequeue(moviments, &moviments->back->queueItem);

  (*x) = Aux->queueItem.x;
  (*y) = Aux->queueItem.y;
}

void cleanQueue(Queue *moviments)
{

  if (moviments->front->next != NULL)
  {
    dequeue(moviments, &moviments->back->queueItem);
    cleanQueue(moviments);
  }
}