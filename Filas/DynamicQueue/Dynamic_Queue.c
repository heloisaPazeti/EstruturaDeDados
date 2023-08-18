#include "Dynamic_Queue.h"
#include "Doub_List_Queue.h"

/////////////////////////////////////////////// STRUCT

typedef struct _queue
{
    List *data;

} Queue;

/////////////////////////////////////////////// CONSTRUCTORS AND DESTROYER

Queue *Queue_Create()
{
    Queue *Q = (Queue*)calloc(1, sizeof(Queue));
    Q -> data = List_Create();

    return Q;
}

void Queue_Destroy(Queue **Q_ref)
{
    Queue *Q = *Q_ref;

    List_Destroy(&Q -> data);
    free(Q);

    *Q_ref = NULL;
}

/////////////////////////////////////////////// ENQUEUE AND DEQUEUE

void Queue_Enqueue(Queue *Q, int val)
{
    List_AddLast(Q -> data, val);
}

int Queue_Dequeue(Queue *Q)
{
    if(Queue_IsEmpty(Q))
    {
            fprintf(stderr, "ERROR, QUEUE IS EMPTY");
            exit(EXIT_FAILURE);
    }
    int val = List_GetFirstVal(Q -> data);
    List_RemoveFirst(Q -> data);
    return val;
}

/////////////////////////////////////////////// PEEK

int Queue_Peek(const Queue *Q)
{
    return List_GetFirstVal(Q -> data);
}

/////////////////////////////////////////////// HELPERS

void Queue_Print(const Queue *Q)
{
    List_Print(Q -> data);
}

bool Queue_IsEmpty(const Queue *Q)
{
		return List_IsEmpty(Q -> data);
}

long Queue_Size(const Queue *Q)
{
		return List_Size(Q -> data);
}
