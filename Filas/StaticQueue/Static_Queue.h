#ifndef STATIC_QUEUE_H_INCLUDED
#define STATIC_QUEUE_H_INCLUDED

#include <stdbool.h>

///////////////////////////////////////// STRUCT

typedef struct _static_queue StaticQueue;

///////////////////////////////////////// CRONSTRUCTORS AND DESTROYERS

StaticQueue *StaticQueue_Create(long capacity);
void StaticQueue_Destroy(StaticQueue **Q_ref);

///////////////////////////////////////// ENQUEUE AND DEQUEUE

void StaticQueue_Enqueue(StaticQueue *Q, int val);
int StaticQueue_Dequeue(StaticQueue *Q);

///////////////////////////////////////// PEEK

int StaticQueue_Peek(const StaticQueue *Q);

///////////////////////////////////////// HELPERS

bool StaticQueue_IsEmpty(const StaticQueue *Q);
bool StaticQueue_IsFull(const StaticQueue *Q);
long StaticQueue_Size(const StaticQueue *Q);
void StaticQueue_Print(const StaticQueue *Q);

#endif // STATIC_QUEUE_H_INCLUDED
