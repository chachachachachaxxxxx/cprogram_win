#include <bits/stdc++.h>
using namespace std;

typedef struct binarySortTree {
    int data;  //结点的数据
    int BF;   //结点的平衡因子
    struct binarySortTree *lchild;
    struct binarySortTree *rchild;
}BiNODE;

/**
 * 给定二叉树的前序和中序遍历序列, 建立一棵二叉树
 * 数组下标从1开始
 * @param preOrder	[大小为arrSize的前序遍历序列]
 * @param inOrder	[大小为arrSize的中序遍历序列]
 * @param arrSize	[序列的长度]
 *
 * @return          [树的根节点root]
 */
BiNODE *NewNODE() // 创建新节点
{
    BiNODE *p = new BiNODE;
    p->BF = 0;
    p->lchild = p->rchild = NULL;
    return p;
}

BiNODE *generateTree(int *preOrder, int *inOrder, int s, int e) // 前序中序生成二叉树
{
    if (s > e)
        return NULL;

    BiNODE *p = NewNODE();
    static int tag = 1;

    for (int i = s; i <= e; i++)
    {
        if (preOrder[tag] == inOrder[i])
        {
            p->data = preOrder[tag++];
            p->lchild = generateTree(preOrder, inOrder, s, i - 1);
            p->rchild = generateTree(preOrder, inOrder, i + 1, e);
            break;
        }
    }
    return p;
}

int initBF(BiNODE *root) // 初始化各结点BF值
{
    if (root == NULL)
        return 0;
    int rh, lh;
    rh = initBF(root->rchild);
    lh = initBF(root->lchild);
    root->BF = rh - lh;

    return (rh > lh ? rh : lh) + 1;
}

BiNODE *buildBTree(int *preOrder, int *inOrder, int arrSize) {
    /** TODO **/
    BiNODE *root = generateTree(preOrder, inOrder, 1, arrSize);
    initBF(root);
    return root;
}

/**
 * 给定二叉树的根节点, 判断该树是否平衡
 * 如果是输出“Yes”，否则输出“No”(不用输出引号)
 * @param root		[二叉树的根节点]
 */
bool isBalance(BiNODE *root) // 递归判断是否为平衡树
{
    if (root == NULL)
        return true;

    if (abs(root->BF) >= 2)
        return false;
    
    if (!isBalance(root->rchild) || !isBalance(root->lchild))
        return false;

    return true;
}

void printIsBalance(BiNODE *root) {
    /** TODO **/
    if (isBalance(root))
        printf("Yes\n");
    else
        printf("No\n");
}

/**
 * 给定二叉树的根节点, 判断该树是否为搜索树
 * 如果是输出“Yes”，否则输出“No”(不用输出引号)
 * @param root		[二叉树的根节点]
 */
const int SUP = 1e8 + 10;
const int INF = -SUP;

bool isSearchTree(BiNODE *root, int ma, int mi) // 递归判断是否为搜索树，设上界ma，下界mi，
{
    if (root == NULL)
        return true;

    bool flag = false;
    if (root->data <= ma && root->data >= mi) 
    {
        // 判断左子树是否符合搜索树定义，则根节点值为左子树上界，同理，根节点值为右子树下界
        flag = isSearchTree(root->lchild, root->data, mi) && isSearchTree(root->rchild, ma, root->data);
    }
    return flag;
}

void printIsSearchTree(BiNODE *root) {
    /** TODO **/
    if (isSearchTree(root, SUP, INF))
    {
        printf("Yes\n");
    }
    else
        printf("No\n");
}


/**
 * 给定二叉树的根节点, 通过仅“跟踪”到叶子结点的一条路径
 * 而不查看树中所有的结点, 返回树的高度并输出这条路径。
 * @param root		[二叉树的根节点]
 *
 * @return			[树的高度]
 */
int getTreeHeight(BiNODE *root) { // 利用BF值递归查找这一路径
    /** TODO **/
    if (root == NULL)
    {
        printf("\n");
        return 0;
    }
    printf("%d ", root->data);
    if (root->BF >= 0)
    {
        return 1 + getTreeHeight(root->rchild);
    }
    else
        return 1 + getTreeHeight(root->lchild);
}


int main() {
    int n;
    scanf("%d", &n);

    int *preOrder = (int *)malloc((n+1)*sizeof(int));
    int *inOrder = (int *)malloc((n+1)*sizeof(int));
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &preOrder[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &inOrder[i]);
    }

    BiNODE *root = buildBTree(preOrder, inOrder, n);
    printIsBalance(root);
    printIsSearchTree(root);
    int treeHeight = getTreeHeight(root);
    printf("%d\n", treeHeight);

    return 0;
}
