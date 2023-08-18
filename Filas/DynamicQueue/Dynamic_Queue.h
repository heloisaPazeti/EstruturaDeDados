#ifndef DYNAMIC_QUEUE_H_INCLUDED
#define DYNAMIC_QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/////////////////////////////////////////////// STRUCT

typedef struct _queue Queue;

/////////////////////////////////////////////// CONSTRUCTORS AND DESTROYER

Queue *Queue_Create();
void Queue_Destroy(Queue **Q_ref);

/////////////////////////////////////////////// ENQUEUE AND DEQUEUE

void Queue_Enqueue(Queue *Q, int val);
int Queue_Dequeue(Queue *Q);

/////////////////////////////////////////////// PEEK

int Queue_Peek(const Queue *Q);

/////////////////////////////////////////////// HELPERS

void Queue_Print(const Queue *Q);
bool Queue_IsEmpty(const Queue *Q);
long Queue_Size(const Queue *Q);

#endif // DYNAMIC_QUEUE_H_INCLUDED
