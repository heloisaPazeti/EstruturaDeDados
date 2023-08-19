#include <stdio.h>
#include <stdlib.h>
#include "Doubly_Linked_List.h"

int main()
{
    List *L = List_Create();

    List_AddFirst(L, 2);
    List_AddFirst(L, 5);
    List_AddFirst(L, 10);
    List_Print(L);

    List_AddLast(L, 50);
    List_AddLast(L, 10);
    List_AddLast(L, 60);
    List_Print(L);

    List_Remove(L, 50);
    List_Remove(L, 2);
    List_Remove(L, 10);
    List_Print(L);

    List_Destroy(&L);

    return 0;
}
