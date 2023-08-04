#include "LinkedList.h"

int main()
{
    LinkedList *L = LinkedList_Create();

    LinkedList_AddFirst(L, 10);
    LinkedList_AddFirst(L, 3);
    LinkedList_AddFirst(L, 2);
    LinkedList_AddLast(L, 2);
    LinkedList_AddLast(L, 5);

    LinkedList_Print(L);

    LinkedList_Remove(L, 2);

    LinkedList_Print(L);

    LinkedList_Remove(L, 5);

    LinkedList_Print(L);

    LinkedList_Remove(L, 10);

    LinkedList_Print(L);

    return 0;
}
