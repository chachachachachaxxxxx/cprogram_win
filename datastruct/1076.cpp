#include <iostream>
#include <string>
using namespace std;

struct node{
    string value;
    int cnt;
    struct node *left;
    struct node *right;
};

int N;
string tree;
node *root;

node *newnode(string st)
{
    node *p = new node;
    p->left = p->right = NULL;
    p->cnt = 1;
    p->value = st;
    return p;
}

void insert(string st)
{
    if (root == NULL)
    {
        node *p = newnode(st);
        root = p;
        return;
    }

    node *p = root;
    node *q = NULL;
    while (p != NULL)
    {
        q = p;
        if (p->value == st)
        {
            p->cnt++;
            return;
        }
        else if (p->value < st)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }
    if (p == NULL)
    {
        node *s = newnode(st);
        if (q->value < st)
        {
            
            q->right = s;
        }
        else
        {
            q->left = s;
        }
    }
}

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%s %.4lf%\n", root->value.c_str(), root->cnt * 100.0 / N);
    inorder(root->right);
}

int main()
{
    cin >> N;
    getchar();
    for (int i = 0; i < N; i++)
    {
        getline(cin, tree);
        insert(tree);
    }
    inorder(root);
}