#ifndef STATIC_STACK_H_INCLUDED
#define STATIC_STACK_H_INCLUDED

#include <stdbool.h>

////////////////////////////////////////// STRUCTS

typedef struct _static_stack_ StaticStack;

////////////////////////////////////////// CONSTRUCTOS AND DESTROYERS

StaticStack *StaticStack_Create(long capacity);
void StaticStack_Destroy(StaticStack **S_ref);

////////////////////////////////////////// PUSH, PEEK AND POP

void StaticStack_Push(StaticStack *S, int val);
int StaticStack_Peek(const StaticStack *S);
int StaticStack_Pop(StaticStack *S);

////////////////////////////////////////// HELPERS

bool StaticStack_IsEmpty(const StaticStack *S);
bool StaticStack_IsFull(const StaticStack *S);
long StaticStack_size(const StaticStack *S);
void StaticStack_Print(const StaticStack *S);

#endif // STATIC_STACK_H_INCLUDED
