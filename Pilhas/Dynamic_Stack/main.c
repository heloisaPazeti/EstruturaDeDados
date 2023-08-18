#include <stdio.h>
#include <stdlib.h>
#include "Dynamic_Stack.h"

int main()
{
    Stack *S = Stack_Create();

    printf("PUSHING NEW NODES\n");
    Stack_Push(S, 2);
    Stack_Push(S, 3);
    Stack_Push(S, 4);
    Stack_Push(S, 5);
    Stack_Print(S);

    printf("\nPEEKING 0-0: %d\n", Stack_Peek(S));

    printf("\nPOPPING : %d\n", Stack_Pop(S));
    Stack_Print(S);

     printf("\nPOPPING : %d\n", Stack_Pop(S));
    Stack_Print(S);

    Stack_Push(S, 10);
    Stack_Push(S, 20);
    Stack_Push(S, 30);
    Stack_Print(S);

    return 0;
}
