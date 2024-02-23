#include "red_black.h"


int main()
{

    Tree* tree = NULL;
    tree = Insert_RB(tree, 10);

    tree = Insert_RB(tree, 12);
    tree = Insert_RB(tree, 8);
    tree = Insert_RB(tree, 11);

    Print_InOrder(tree -> root);

    return 0;
}
