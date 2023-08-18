#include <stdio.h>
#include <stdlib.h>
#include "Static_Queue.h"

int main()
{
    StaticQueue *Q = StaticQueue_Create(10);

    printf("ENQUEUE NEW VALUES\n");
    StaticQueue_Enqueue(Q, 2);
    StaticQueue_Enqueue(Q, 5);
    StaticQueue_Enqueue(Q, 8);
    StaticQueue_Enqueue(Q, 10);

    StaticQueue_Print(Q);

    printf("\nPEEKING: %d\n\n", StaticQueue_Peek(Q));

    printf("DEQUEUE VALUE: %d\n", StaticQueue_Dequeue(Q));
    StaticQueue_Print(Q);

    printf("\nDEQUEUE VALUE: %d\n", StaticQueue_Dequeue(Q));
    StaticQueue_Print(Q);

    printf("\nENQUEUE NEW VALUES\n");
    StaticQueue_Enqueue(Q, 3);
    StaticQueue_Enqueue(Q, 4);
    StaticQueue_Print(Q);
    return 0;
}
