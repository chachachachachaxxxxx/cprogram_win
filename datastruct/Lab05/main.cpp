#include <iostream>
#include "BTree.cpp"
#include <fstream>
using namespace std;

int main()
{
    // BiNODE *ttTree = buildTree_twoTags();
    // preorder(ttTree);
    // preorderRecursive(ttTree);
    // inorder(ttTree);
    // inorderRecursive(ttTree);
    // postorder(ttTree);
    // postorderRecursive(ttTree);
    // layerorder(ttTree);
    // cout << endl;

    // BiNODE *preTree = buildTree_pre_in();
    // preorder(preTree);
    // preorderRecursive(preTree);
    // inorder(preTree);
    // inorderRecursive(preTree);
    // postorder(preTree);
    // postorderRecursive(preTree);
    // layerorder(preTree);

    BiNODE *postTree = buildTree_post_in();
    // preorder(postTree);
    // preorderRecursive(postTree);
    // inorder(postTree);
    // inorderRecursive(postTree);
    // postorder(postTree);
    // postorderRecursive(postTree);
    layerorder(postTree);

    cout << "NodeNum:           " << getNodeNum(postTree) << endl;
    cout << "TreeHeight:        " << getTreeHeight(postTree) << endl;
    cout << "isFull:            " << isFull(postTree) << endl;
    cout << "isComplete:        " << isComplete(postTree) << endl;
    cout << "isBinarySearchTree:" << isBinarySearchTree(postTree) << endl;
}