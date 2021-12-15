#include <iostream>
#include <string>
using namespace std;

struct node{
    char value;
    struct node *left, *right;
};

const int MAXN = 51;
char pre[MAXN];
char in[MAXN];

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
    if (p== NULL)
        return;
    cout << p->value;
    preorder(p->left);
    preorder(p->right);
}

node *newnode()
{
    node *p = new node;
    p->left = p->right = NULL;
    return p;
}

node *generatetree(char *pre, char *in, int s, int e)
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
            p->left = generatetree(pre, in, s, i - 1);
            p->right = generatetree(pre, in, i + 1, e);
            break;
        }
    }
    return p;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> pre[i];
    for (int i = 0; i < N; i++)
        cin >> in[i];

    node *p = generatetree(pre, in, 0, N - 1);
    int h = getheight(p);
    cout << h << endl;
    // preorder(p);
}