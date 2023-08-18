#include "Dynamic_Stack.h"
#include "Doub_List.h"

#include <stdlib.h>

////////////////////////////////////////// STRUCT

typedef struct _static_stack_
{
    List *data; //REFERENCE TO DOUBLE LINKED LIST

} Stack;

////////////////////////////////////////// CONSTRUCTORS AND DESTROYERS

Stack *Stack_Create()
{
    Stack *S = (Stack*)calloc(1, sizeof(Stack));
    S -> data = List_Create();

    return S;
}

void Stack_Destroy(Stack **S_ref)
{
    Stack *S = *S_ref;
    List_Destroy(&S -> data);

    free(S);
    *S_ref = NULL;
}

////////////////////////////////////////// PUSH, PEEK AND POP

void Stack_Push(Stack *S, int val)
{
    List_AddLast(S -> data, val);
}

int Stack_Peek(const Stack *S)
{
    if(Stack_IsEmpty(S))
    {
        printf("A pilha está vazia...");
        exit(EXIT_FAILURE);
    }
    return List_GetLastValue(S -> data);
}


int Stack_Pop(Stack *S)
{
    if(Stack_IsEmpty(S))
    {
        printf("A pilha está vazia...");
        exit(EXIT_FAILURE);
    }

    int val = List_GetLastValue(S -> data);
    List_RemoveLast(S -> data);

    return val;
}

////////////////////////////////////////// HELPERS

bool Stack_IsEmpty(const Stack *S)
{
    return List_IsEmpty(S -> data);
}

size_t Stack_Size(const Stack *S)
{
    return List_Size(S -> data);
}

void Stack_Print(const Stack *S)
{
    List_Print(S -> data);
}
