#include <stdio.h>
#include <stdlib.h>
#include "Dynamic_Queue.h"

int main()
{
    Queue *Q = Queue_Create();

    printf("ENQUEUE NEW VALUES... \n");
    Queue_Enqueue(Q, 40);
    Queue_Enqueue(Q, 1);
    Queue_Enqueue(Q, 70);
    Queue_Enqueue(Q, 4);
    Queue_Print(Q);

    printf("\nPEEKING VALUE: %d\n\n", Queue_Peek(Q));
    printf("\nDEQUEUE VALUES: %d", Queue_Dequeue(Q));
    Queue_Print(Q);
    printf("\nDEQUEUE VALUES: %d", Queue_Dequeue(Q));
    Queue_Print(Q);

    printf("\nENQUEUE NEW VALUES... \n");
    Queue_Enqueue(Q, 2);
    Queue_Enqueue(Q, 5);
    Queue_Enqueue(Q, 80);
    Queue_Enqueue(Q, 1000);
    Queue_Print(Q);

    Queue_Destroy(&Q);

    return 0;
}
