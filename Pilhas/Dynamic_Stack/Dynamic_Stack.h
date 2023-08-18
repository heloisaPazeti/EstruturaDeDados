#ifndef DYNAMIC_STACK_H_INCLUDED
#define DYNAMIC_STACK_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>

////////////////////////////////////////// STRUCT

typedef struct _static_stack_ Stack;

////////////////////////////////////////// CONSTRUCTORS AND DESTROYERS

Stack *Stack_Create();
void Stack_Destroy(Stack **S_ref);

////////////////////////////////////////// PUSH, PEEK AND POP

void Stack_Push(Stack *S, int val);
int Stack_Peek(const Stack *S);
int Stack_Pop(Stack *S);

////////////////////////////////////////// HELPERS

bool Stack_IsEmpty(const Stack *S);
size_t Stack_Size(const Stack *S);
void Stack_Print(const Stack *S);

#endif // DYNAMIC_STACK_H_INCLUDED
