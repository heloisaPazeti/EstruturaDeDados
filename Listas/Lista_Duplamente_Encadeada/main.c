#include <stdio.h>
#include <stdlib.h>
#include "Doubly_Linked_List.h"

int main()
{
    List *L = List_Create();

    List_Print(L);
    List_AddFirst(L, 2);
    List_AddFirst(L, 5);
    List_AddFirst(L, 10);
    List_Print(L);

    return 0;
}
