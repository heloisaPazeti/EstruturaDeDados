#include <stdio.h>
#include <stdlib.h>
#include "Circ_List.h"

int main()
{
    CircList *L = CircList_Create();

    CircList_AddFirst(L, 10);
    CircList_AddFirst(L, 1);
    CircList_AddFirst(L, 2);
    CircList_AddFirst(L, 2);
    CircList_Print(L);

    CircList_AddLast(L, 10);
    CircList_AddLast(L, 2);
    CircList_AddLast(L, 50);
    CircList_Print(L);

    CircList_Remove(L, 2);
    CircList_Remove(L, 50);
    CircList_Remove(L, 1);
    CircList_Print(L);

    CircList_Destroy(&L);

    return 0;
}
