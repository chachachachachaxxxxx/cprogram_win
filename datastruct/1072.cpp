#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct node{
    int value;
    struct node *left, *right;
};

const int MAXN = 1e4+10;
int pre[MAXN];
int in[MAXN];

int getheight(node *root)
{
    if (root == NULL)
        return 0;
    int rh = getheight(root->right);
    int lh = getheight(root->left);

    return (rh > lh ? rh : lh) + 1;
}

void preorder(node* p)
{
    if (p == NULL)
        return;
    preorder(p->left);
    preorder(p->right);
    cout << p->value << endl;
}

node *newnode()
{
    node *p = new node;
    p->left = p->right = NULL;
    return p;
}

node *generatetree(int *pre, int *in, int s, int e)
{
    if (s > e)
        return NULL;

    node *p = newnode();
    static int tag = 0;
    for (int i = s; i <= e; i++)
    {
        if (in[i] == pre[tag])
        {
            p->value = pre[tag++];
            cout << p->value << endl;
            p->left = generatetree(pre, in, s, i - 1);
            p->right = generatetree(pre, in, i + 1, e);
            break;
        }
    }
    return p;
}

int main()
{
    int N = 0;
    /* while (cin >> pre[N])
    {
        in[N] = pre[N];
        N++;
    } */
    while (N < 1000)
    {
        in[N] = N + 1;
        pre[N] = in[N];
        N++;
    }
    sort(in, in + N);
    node *p = generatetree(pre, in, 0, N - 1);
    // int h = getheight(p);
    // cout << h << endl;
    // preorder(p);
}