#include "red_black.h"


int main()
{
    Tree* tree = NULL;
    tree = Insert_RB(tree, 10);
    tree = Insert_RB(tree, 5);
    tree = Insert_RB(tree, 30);
    tree = Insert_RB(tree, 40);
    tree = Insert_RB(tree, 25);
    tree = Insert_RB(tree, 38);

    Remove(tree, 30);
    //Remove(tree, 15);
    Print_InOrder(tree -> root);

    return 0;
}
