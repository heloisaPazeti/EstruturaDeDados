#include <stdio.h>
#include <stdlib.h>
#include "Binary_Tree.h"

int main()
{
    Tree *T1 = Tree_Create();

    printf("USING V1\n");
    Tree_Insert(T1, 50);

    /*
    Tree *T2 = Tree_Create();
    printf("USING V2\n");
    Node *p = NULL;
    p = Tree_Insert_V2(T2, T2->mainRoot, 50);
    p = Tree_Insert_V2(T2, p, 50);
    */
    return 0;
}
