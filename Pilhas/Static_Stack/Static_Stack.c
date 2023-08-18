#include "Static_Stack.h"
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////// STRUCTS

typedef struct _static_stack_
{
    int *data;
    long topIndex;
    long capacity;

} StaticStack;

////////////////////////////////////////// CONSTRUCTOS AND DESTROYERS

StaticStack *StaticStack_Create(long capacity)
{
    StaticStack *S = (StaticStack*)calloc(1, sizeof(StaticStack));

    S -> capacity = capacity;
    S -> topIndex = -1;
    S -> data = (int*)calloc(S -> capacity, sizeof(int));

    return S;
}

void StaticStack_Destroy(StaticStack **S_ref)
{
    StaticStack *S = *S_ref;
    free(S -> data);
    free(S);

    *S_ref = NULL;
}

////////////////////////////////////////// PUSH, PEEK AND POP

void StaticStack_Push(StaticStack *S, int val)
{
    if(StaticStack_IsFull(S))
    {
        exit(EXIT_FAILURE);
    }

    S -> topIndex++;
    S -> data[S -> topIndex] = val;
}

int StaticStack_Peek(const StaticStack *S)
{
    if(StaticStack_IsEmpty(S))
    {
        exit(EXIT_FAILURE);
    }

    return S -> data[S -> topIndex];
}

int StaticStack_Pop(StaticStack *S)
{
    if(StaticStack_IsEmpty(S))
    {
        exit(EXIT_FAILURE);
    }

    int val = S -> data[S -> topIndex];
    S -> topIndex--;

    return val;
}

////////////////////////////////////////// HELPERS

bool StaticStack_IsEmpty(const StaticStack *S)
{
    return S -> topIndex <= -1;
}

bool StaticStack_IsFull(const StaticStack *S)
{
    return S -> topIndex >= (S -> capacity - 1);
}

long StaticStack_size(const StaticStack *S)
{
    return (S -> topIndex + 1);
}

void StaticStack_Print(const StaticStack *S)
{
    if(!StaticStack_IsEmpty(S))
    {
        printf("\nCapacity: %ld\n", S -> capacity);
        printf("topIndex: %ld\n", S -> topIndex);
        printf("Values: ");
        for(long i = 0; i <= S -> topIndex; i++)
        {
            printf("%d -> ", S -> data[i]);
        }
        printf("NULL\n");
    }
    else
        printf("Stack is Empty...\n");
}
