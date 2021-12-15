#include <iostream>
using namespace std;
const int MAXN = 1e4 + 10;

struct node{
    int value;
    struct node *left, *right;
};

node *newnode()
{
    node *p = new node;
    p->left = p->right = NULL;
    return p;
}

node *generatetree(int *post, int *in, int s, int e, int N)
{
    if (s > e)
        return NULL;

    node *p = newnode();
    static int tag = 0;
    for (int i = s; i <= e; i++)
    {
        if (in[i] == post[N - 1 - tag])
        {
            p->value = post[N - 1 - tag++];
            p->right = generatetree(post, in, i + 1, e, N);
            p->left = generatetree(post, in, s, i - 1, N);
            break;
        }
    }
    return p;
}

int order[MAXN * 2];

int anssum = 1e8;
int ansnil;

void dfs(node *p, int sum)
{
    if (p->left == NULL && p->right == NULL)
    {
        sum += p->value;
        if (sum < anssum || (sum == anssum && p->value < ansnil ))
        {
            ansnil = p->value;
            anssum = sum;
        }
        return;
    }
    if (sum >= anssum)
        return;

    if (p->left != NULL)
        dfs(p->left, sum + p->value);
    if (p->right != NULL)
        dfs(p->right, sum + p->value);
}

void preorder(node* p)
{
    if (p== NULL)
        return;

    
    preorder(p->left);
    cout << p->value << " ";
    preorder(p->right);
}

int main()
{
    int N2 = 0;
    while (cin >> order[N2++])
        ;
    // for (int i = 0; i < N2; i++)
    //     cout << order[i] << " ";
    N2--;
    // cout << N2 << endl;
    node *p = generatetree(order + N2 / 2, order, 0, N2 / 2 - 1, N2 / 2);
    dfs(p, 0);
    // preorder(p);
    cout << ansnil << endl;
}