#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

/**
 * 二叉查找树结点结构
 */
typedef struct binarySortTree {
    int data;                       /**<结点键值 */
    struct binarySortTree *lchild;  /**<左子节点 */
    struct binarySortTree *rchild;  /**<右子节点 */
} BiNODE;

/**
 * 建立一颗以nodeArr作为结点键值的一棵查找树
 * 数组下标从1开始
 * @param nodeArr   [大小为arrSize的数组]
 * @param arrSize   [数组大小]
 *
 * @return          [树的根节点root的指针]
 */
BiNODE *NewNODE(int key) // 创建新结点
{
    BiNODE *p = new BiNODE;
    p->data = key;
    p->lchild = p->rchild = NULL;
    return p;
}

void Insert(BiNODE* node, BiNODE** root) // 将结点p插入以root为根的树中
{
    if (*root == NULL)
    {
        *root = node;
        return;
    }

    BiNODE *p = *root;
    BiNODE *q = *root;
    while (p != NULL)
    {
        q = p;
        if (node->data < p->data)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        }
    }

    if (node->data < q->data)
        q->lchild = node;
    else
    {
        q->rchild = node;
    }
}

BiNODE *buildTree(int *nodeArr, int arrSize) {
    /** TODO **/
    BiNODE *root = NULL;

    for (int i = 1; i <= arrSize; i++)
    {
        BiNODE *p = NewNODE(nodeArr[i]);
        // printf("%d\n", p->data);
        Insert(p, &root);
    }

    return root;
}

/**
 * 中序输出这棵查找树
 * 无返回值, 输出一行, 数与数之间有空格, 行末无多余空格
 * 具体参考文档上的样例
 * @param root      [树的根节点]
 */
void InOrder(BiNODE* root) // 递归中序
{
    if (root == NULL)
        return;

    InOrder(root->lchild);
    printf("%d ", root->data);
    InOrder(root->rchild);
}

void printInOrder(BiNODE *root) {
    /** TODO **/

    InOrder(root);
    printf("\n");
}

/**
 * 判断这棵查找树是否平衡
 * 如果是输出"Yes", 否则输出"No"(不用输出引号)
 * 具体参考文档上的样例
 * @param root      [树的根节点]
 */

int depth(BiNODE *root) // 返回树高，只有根结点高度默认为1
{
    if (root == NULL)
        return 0;

    int m1 = depth(root->lchild);
    int m2 = depth(root->rchild);

    return (m1 > m2 ? m1 : m2) + 1;
}

bool isBalance(BiNODE *root) // 判断某树是否为平衡树
{
    if (root == NULL)
        return true;

    int lh = depth(root->lchild);
    int rh = depth(root->rchild);

    if (abs(rh - lh) > 1)
        return false;
    
    if (isBalance(root->lchild) && isBalance(root->rchild))
        return true;

    return false;
}

void printIsBalance(BiNODE *root) {
    /** TODO **/

    if (isBalance(root))
        printf("Yes\n");
    else
        printf("No\n");
}

/**
 * 输出这颗查找树查找结点的平均比较次数, 结果保留6位小数
 * 具体参考文档上的样例
 * @param root      [树的根节点]
 */
int size(BiNODE *root) // 返回树的结点个数
{
    if (root == NULL)
        return 0;

    return 1 + size(root->lchild) + size(root->rchild);
}

void printAVG(BiNODE *root) {
    /** TODO **/
    
    int N = size(root);
    int sum = 0;

    BiNODE** queue = new BiNODE*[N]; // 层序遍历整颗二叉树
    int *dep = new int[N];

    int front = 0;
    int rear = 0;

    dep[rear] = 1;
    queue[rear++] = root;
    
    BiNODE *p = NULL;
    while (front < rear)
    {
        sum += dep[front];
        p = queue[front++];

        if (p->lchild != NULL)
        {
            queue[rear++] = p->lchild;
            dep[rear - 1] = dep[front - 1] + 1;
        }
        if (p->rchild != NULL)
        {
            queue[rear++] = p->rchild;
            dep[rear - 1] = dep[front - 1] + 1;
        }
    }

    printf("%f\n", sum * 1.0 / N);
    delete[] queue;
    delete[] dep;
}

int main() {
    int n;
    scanf("%d", &n);

    int *nodeArr = (int *)malloc((n+1)*sizeof(int));
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &nodeArr[i]);
    }

    BiNODE *root = buildTree(nodeArr, n);
    printInOrder(root);
    printIsBalance(root);
    printAVG(root);

    return 0;
}
