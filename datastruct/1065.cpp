#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXM = 100;
const int MAXN = 1010;

typedef struct node{
    int value;
    struct node* kids[MAXM];
} NODE;

void preorder(NODE *root)
{
    if (root == NULL)
        return;
    cout << root->value << " ";
    int i = 0;
    while (root->kids[i] != NULL)
    {
        preorder(root->kids[i]);
        i++;
    }
}

void priorder(NODE *root)
{
    if (root == NULL)
        return;
    int i = 0;
    while (root->kids[i] != NULL)
    {
        priorder(root->kids[i]);
        i++;
    }
    cout << root->value << " ";
}

void layerorder(NODE *root)
{
    queue<NODE *> st;
    st.push(root);
    NODE *p = NULL;
    while (!st.empty())
    {
        p = st.front();
        st.pop();
        cout << p->value << " ";
        int i = 0;
        while (p->kids[i] != NULL)
        {
            st.push(p->kids[i]);
            i++;
        }
    }
}

void nilout(NODE *root)
{
    if (root->kids[0] == NULL)
    {
        cout << root->value << " ";
        return;
    }
    int i = 0;
    while (root->kids[i] != NULL)
    {
        nilout(root->kids[i]);
        i++;
    }
}

int size(NODE *root)
{
    if (root->kids[0] == NULL)
        return 1;
    int s = 1;
    int i = 0;
    while (root->kids[i] != NULL)
    {
        s += size(root->kids[i]);
        i++;
    }
    return s;
}

int nilsize(NODE *root)
{
    if (root->kids[0] == NULL)
        return 1;
    int s = 0;
    int i = 0;
    while (root->kids[i] != NULL)
    {
        s += nilsize(root->kids[i]);
        i++;
    }
    return s;
}

int depth(NODE *root)
{
    if (root->kids[0] == NULL)
        return 0;
    int i = 0;
    int dc = 0;
    while (root->kids[i] != NULL)
    {
        if (depth(root->kids[i]) > dc)
            dc = depth(root->kids[i]);
        i++;
    }
    return dc + 1;
}

NODE* InitialNode(int key)
{
    NODE *p = new NODE;
    p->value = key;
    for (int i = 0; i < MAXM; i++)
        p->kids[i] = NULL;
    return p;
}

void destroy(NODE* root)
{
    int i = 0;
    while (root->kids[i] != NULL)
    {
        destroy(root->kids[i]);
        i++;
    }
    delete root;
}

NODE *todes[MAXN];
NODE *root;

typedef struct pnode{
    int value;
    int parent;
} PNODE;
PNODE a[MAXN];

NODE* buildTree(PNODE *input, int N)
{
    if (N <= 0)
        return NULL;
    root = InitialNode(input[0].value);
    todes[input[0].value] = root;

    NODE *p = NULL;
    // NODE *parent = root;
    // int j = 0;
    for (int i = 1; i < N; i++)
    {
        p = InitialNode(input[i].value);
        todes[input[i].value] = p;
        // if (parent != todes[input[i].parent])
        // {
        //     parent = todes[input[i].parent];

        // }
        int j = 0;
        while (todes[input[i].parent]->kids[j] != NULL)
            j++;
        todes[input[i].parent]->kids[j] = p;
    }
    return root;
}

bool cmp(PNODE a, PNODE b)
{
    if (a.parent != b.parent)
        return a.parent < b.parent;
    else
        return a.value < b.value;
}

int main()
{
    int index, parent;
    int N = 0;
    while (cin >> index >> parent)
    {
        a[N].value = index;
        a[N].parent = parent;
        N++;
    }
    sort(a, a + N, cmp);
    // for (int i = 0; i < N; i++)
    //     cout << a[i].parent << endl;

    root = buildTree(a, N);
    preorder(root);
    cout << endl;

    priorder(root);
    cout << endl;

    layerorder(root);
    cout << endl;

    cout << size(root) << endl;

    nilout(root);
    cout << endl;

    cout << nilsize(root) << endl;

    cout << depth(root) << endl;
}