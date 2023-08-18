#include "Static_Queue.h"
#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////// STRUCT

typedef struct _static_queue
{
    int *data;
    long capacity;
    long size;
    long begin;
    long end;

} StaticQueue;

///////////////////////////////////////// CRONSTRUCTORS AND DESTROYERS

StaticQueue *StaticQueue_Create(long capacity)
{
    StaticQueue *Q = (StaticQueue*)calloc(1, sizeof(StaticQueue));

    Q -> data = (int*)calloc(capacity, sizeof(int));
    Q -> capacity = capacity;
    Q -> size = 0;
    Q -> begin = 0;
    Q -> end = 0;


    return Q;
}

void StaticQueue_Destroy(StaticQueue **Q_ref)
{
    StaticQueue *Q = *Q_ref;
    free(Q -> data);
    free(Q);
    *Q_ref = NULL;
}

///////////////////////////////////////// ENQUEUE AND DEQUEUE

void StaticQueue_Enqueue(StaticQueue *Q, int val)
{
    if(StaticQueue_IsFull(Q))
    {
            fprintf(stderr, "ERROR IN ENQUEUE, IT'S FULL.");
            exit(EXIT_FAILURE);
    }

    Q -> data[Q -> end] = val;
    Q -> end = (Q -> end + 1) % Q -> capacity;
    Q -> size++;
}

int StaticQueue_Dequeue(StaticQueue *Q)
{
		if(StaticQueue_IsEmpty(Q))
		{
				fprintf(stderr, "ERROR IN DEQUEUE, IT'S EMPTY.");
				exit(EXIT_FAILURE);
		}

		int val = Q -> data[Q -> begin];
		Q -> begin = (Q -> begin + 1) % Q -> capacity;
		Q -> size--;
		return val;
}

///////////////////////////////////////// PEEK

int StaticQueue_Peek(const StaticQueue *Q)
{
    if(StaticQueue_IsEmpty(Q))
    {
            fprintf(stderr, "ERROR IN PEEK, IT'S EMPTY.");
            exit(EXIT_FAILURE);
    }

    return Q -> data[Q -> begin];
}

///////////////////////////////////////// HELPERS

bool StaticQueue_IsEmpty(const StaticQueue *Q)
{
    return (Q -> size == 0);
}

bool StaticQueue_IsFull(const StaticQueue *Q)
{
    return (Q -> size == Q -> capacity);
}

long StaticQueue_Size(const StaticQueue *Q)
{
    return Q -> size;
}

void StaticQueue_Print(const StaticQueue *Q)
{
    printf("Capacity: %ld\n", Q -> capacity);
    printf("Size: %ld\n", Q -> size);
    printf("Begin: %ld\n", Q -> begin);
    printf("End: %ld\n", Q -> end);

    long s, i;

    for (s = 0, i = Q->begin;
         s < Q->size;
         s++, i = (i + 1) % Q->capacity) {
        printf("%d, ", Q->data[i]);
    }

    printf("END");
    puts("");
}
