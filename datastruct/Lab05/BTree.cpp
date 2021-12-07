#include <iostream>
#include <stack>
#include <queue>
using namespace std;
const int MAXN = 1e5;
const int MAX = 1e8;
const int MIN = -1e8;

typedef struct binaryTreeNODE//二叉树结点结构
{
    int data;//结点值
    struct binaryTreeNODE *lchild;//左子节点
    struct binaryTreeNODE *rchild;//右子节点
}BiNODE; //树的结构

BiNODE* buildTree_twoTags();//前序序列+两个标志位建树
BiNODE* buildTree_pre_in();//前序+中序建树
BiNODE* buildTree_post_in();//后序+中序建树
void preorder(BiNODE *root);               //非递归前序遍历
void preorderRecursive(BiNODE *root);      //递归前序遍历
void inorder(BiNODE *root);                //非递归中序遍历
void inorderRecursive(BiNODE *root);       //递归中序遍历
void postorder(BiNODE *root);              //非递归后序遍历
void postorderRecursive(BiNODE *root);     //递归后序遍历
void layerorder(BiNODE* root);//层次遍历
int getNodeNum(BiNODE* root);//求结点个数
int getTreeHeight(BiNODE* root);//无需输出，返回即可
bool isFull(BiNODE* root);//判断是否是满二叉树
bool isComplete(BiNODE* root);//判断是否是完全二叉树
bool isBinarySearchTree(BiNODE* root);//判断是否是二叉搜索树


BiNODE* NewNODE() // 创建一个新结点
{
    BiNODE *p = new BiNODE;
    p->data = 0;
    p->lchild = p->rchild = NULL;
    return p;
}

BiNODE* buildTree_twoTags()
{
    int N;
    cin >> N;
    int *tree = new int[N * 3]; // 记录前序加两个标志位
    for (int i = 0; i < N; i++) // 余0为左标记位，余1为数据，余2为右标记位
        cin >> tree[i * 3] >> tree[i * 3 + 1] >> tree[i * 3 + 2]; // 读入数据
    
    BiNODE *root, *p, *q, *stack[MAXN];
    if (N == 0)
        return NULL;
    int top, i;

    root = NewNODE();
    p = root;
    top = 0;
    for (i = 0; i < N - 1; i++)
    {
        p->data = tree[i * 3 + 1];
        if (tree[i * 3 + 2] == 0)
            stack[top++] = p;
        else
            p->rchild = NULL;

        q = NewNODE();
        if (tree[i * 3] == 0)
            p->lchild = q;
        else
        {
            p->lchild = NULL;
            p = stack[--top];
            p->rchild = q;
        }
        p = q;
    }
    p->data = tree[(N - 1) * 3 + 1];
    p->lchild = NULL;
    p->rchild = NULL;

    delete[] tree;
    return root;
}


// 前序中序确定二叉树的辅助函数，并返回根节点
BiNODE* generateTree_pre(int pre[], int mid[], int s, int e) 
{
    if (s > e)
        return NULL;

    static int tag = 0; // 指向下一个要找的根节点
    BiNODE *p = NewNODE();

    for (int i = s; i <= e; i++)
    {
        if (pre[tag] == mid[i])
        {
            p->data = pre[tag++];

            // 左半元素生成左子树
            p->lchild = generateTree_pre(pre, mid, s, i - 1);
            // 再生成右子树
            p->rchild = generateTree_pre(pre, mid, i + 1, e);
            break;
        }
    }
    return p;
}

BiNODE* buildTree_pre_in()
{
    int N; // 输入
    cin >> N;
    int *pre, *mid;
    pre = new int[N];
    mid = new int[N];
    for (int i = 0; i < N; i++)
        cin >> pre[i];

    for (int i = 0; i < N; i++)
        cin >> mid[i];

    BiNODE *root;
    root = generateTree_pre(pre, mid, 0, N - 1);

    delete[] pre;
    delete[] mid;
    return root;
}

BiNODE* generateTree_post(int *post, int *mid, int s, int e, int N) // 后序中序确定二叉树的辅助函数
{
    if (s > e)
        return NULL;

    static int tag = 0;
    BiNODE *p = NewNODE();

    for (int i = s; i <= e; i++)
    {
        if (post[N - tag - 1] == mid[i])
        {
            p->data = post[N - 1 - tag++];
            p->rchild = generateTree_post(post, mid, i + 1, e, N);
            p->lchild = generateTree_post(post, mid, s, i - 1, N);
            break;
        }
    }
    return p;
}

BiNODE* buildTree_post_in()
{
    int N;
    cin >> N;
    int *post, *mid;
    post = new int[N];
    mid = new int[N];
    for (int i = 0; i < N; i++)
        cin >> post[i];

    for (int i = 0; i < N; i++)
        cin >> mid[i];

    BiNODE *root;
    root = generateTree_post(post, mid, 0, N - 1, N);

    delete[] post;
    delete[] mid;
    return root;
}





void preorder(BiNODE* root)
{
    if (root == NULL)
        return;

    stack<BiNODE *> s;
    s.push(root); // 根节点入栈
    BiNODE *p;
    while (!s.empty())
    {
        p = s.top();
        s.pop();    
        if (p == NULL) // 如果取到空结点就跳过
            continue;

        cout << p->data << endl; // 输出
        s.push(p->rchild); // 先放右子节点
        s.push(p->lchild); // 再放左子节点
    }
}

void inorder(BiNODE *root)
{
    if (root == NULL)
        return;

    stack<BiNODE *> s;
    BiNODE *p = root;
    while (p != NULL || !s.empty()) // 当前结点不空或者栈不空
    {
        while (p != NULL) // 将当前节点的左子结点全部入栈
        {
            s.push(p);
            p = p->lchild;
        }
        if (!s.empty()) // 若是栈不空
        {
            p = s.top();
            cout << p->data << endl; // 取栈时输出
            s.pop();
            p = p->rchild; // 将当前节点 设为当前节点的右子节点
        }
    }
}

void postorder(BiNODE *root)
{
    if (root == NULL)
        return;
    stack<pair<BiNODE *, bool>> s;
    // s.push(make_pair(root, false));

    // cout << endl;
    BiNODE *p = root;
    while (p != NULL || !s.empty()) // 当前结点不空或者栈不空
    {
        while (p != NULL) // 将当前节点的左子结点全部入栈
        {
            s.push(make_pair(p, false));
            p = p->lchild;
        }

        if (!s.empty()) // 若是栈不空
        {
            if (s.top().second == false) // 取栈时发现其右子节点没有如果栈
            {
                s.top().second = true;
                p = s.top().first->rchild; // 将当前节点设置为右子节点
            }
            else
            {
                cout << s.top().first->data << endl; // 出栈并输出
                s.pop();
            }
        }
    }
}

void preorderRecursive(BiNODE* root)
{
    if (root == NULL)
        return;

    cout << root->data << endl;
    preorderRecursive(root->lchild);
    preorderRecursive(root->rchild);
}

void inorderRecursive(BiNODE* root)
{
    if (root == NULL)
        return;
    
    inorderRecursive(root->lchild);
    cout << root->data << endl;
    inorderRecursive(root->rchild);
}

void postorderRecursive(BiNODE* root)
{
    if (root == NULL)
        return;

    postorderRecursive(root->lchild);
    postorderRecursive(root->rchild);
    cout << root->data << endl;
}

void layerorder(BiNODE* root)
{
    if (root == NULL)
        return;

    queue<BiNODE *> que;
    que.push(root);
    BiNODE *p;
    while (!que.empty())
    {
        p = que.front();
        que.pop();
        cout << p->data << endl;

        if (p->lchild!=NULL)
            que.push(p->lchild);
        if (p->rchild != NULL)
            que.push(p->rchild);
    }
}



int getNodeNum(BiNODE* root) // 用递归求解节点数
{
    if (root == NULL)
        return 0;

    return 1 + getNodeNum(root->lchild) + getNodeNum(root->rchild);
}

int getTreeHeight(BiNODE* root) // 只有根节点的树高认为是1
{
    if (root == NULL)
        return 0;

    int m1 = getTreeHeight(root->rchild);
    int m2 = getTreeHeight(root->lchild);

    return 1 + (m1 > m2 ? m1 : m2);
}

bool isFull(BiNODE* root)
{
    if (root == NULL)
        return true;

    int H = getTreeHeight(root);
    int N = getNodeNum(root);

    int HN = 1;
    for (int i = 0; i < H; i++)
        HN *= 2;
    HN--;
    if (HN == N)
        return true;

    return false;
}

bool isComplete(BiNODE* root)
{
    if (root == NULL)
        return true;

    queue<BiNODE*> que;
    que.push(root);
    BiNODE *p;
    bool flag = true;
    while (!que.empty())
    {
        p = que.front();
        que.pop();

        if (p->lchild != NULL)
        {
            que.push(p->lchild);
            if (flag == false)
                return false;
        }
        else
            flag = false;

        if (p->rchild != NULL)
        {
            que.push(p->rchild);
            if (flag == false)
                return false;
        }
        else
            flag = false;
    }
    return true;
}

int max(BiNODE *root) // 查询树中的最大值
{
    if (root == NULL)
        return MIN;

    int m = root->data;
    int m1 = max(root->lchild);
    int m2 = max(root->rchild);
    
    if (m1 > m)
        m = m1;
    if (m2 > m)
        m = m2;

    return m;
}

int min(BiNODE* root) // 查询树中的最小值
{
    if (root == NULL)
        return MAX;

    int m = root->data;
    int m1 = min(root->lchild);
    int m2 = min(root->rchild);
    
    if (m1 < m)
        m = m1;
    if (m2 < m)
        m = m2;

    return m;
}

bool isBinarySearchTree(BiNODE* root)
{
    if (root == NULL)
        return true;

    bool flag = true;
    if (max(root->lchild) >= root->data)
        flag = false;
    if (min(root->rchild) <= root->data)
        flag = false;
    
    if (!isBinarySearchTree(root->lchild))
        flag = false;
    if (!isBinarySearchTree(root->rchild))
        flag = false;

    return flag;
}
