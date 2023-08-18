#include <stdio.h>
#include <stdlib.h>
#include "Static_Stack.h"

int main()
{
    StaticStack *S = StaticStack_Create(5);
    StaticStack_Print(S);

    StaticStack_Push(S, 2);
    StaticStack_Push(S, 3);
    StaticStack_Push(S, 4);
    StaticStack_Push(S, 5);
    StaticStack_Print(S);

    printf("\nPEEKING 0-0: %d\n", StaticStack_Peek(S));
    StaticStack_Print(S);

    printf("\nPOPPING : %d\n", StaticStack_Pop(S));
    StaticStack_Print(S);

     printf("\nPOPPING : %d\n", StaticStack_Pop(S));
    StaticStack_Print(S);

    StaticStack_Push(S, 10);
    StaticStack_Push(S, 20);
    StaticStack_Push(S, 30);
    StaticStack_Print(S);

    return 0;
}
