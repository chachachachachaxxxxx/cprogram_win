#include <iostream>
#include "trees.h"
using namespace std;

int main()
{
    int a[] = {2, 9, 7, 8, 5};
    BST bst(a, 5);
    // midOrder(bst.Root());
    // printf("\n");
    // preOrder(bst.Root());
    // printf("\n");
    // nextOrder(bst.Root());
    // printf("\n");
    layerOrder(bst.Root());
    // printf("\n");
    //printf("%p", bst.Root());
    // printf("%p\n%p\n", bst.Root()->lchild, bst.Root()->rchild);
    return 0;
}