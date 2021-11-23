#include <iostream>
#include <string>
using namespace std;
const int MAXN = 30;
const int MAXM = 10;

typedef struct node{
    char value;
    struct node* kids[MAXM];
}NODE;

typedef struct lnode{
    char value;
    int level;
} LNODE;

void priorder(NODE *root)
{
    int i = 0;
    while (root->kids[i] != NULL)
    {
        priorder(root->kids[i]);
        i++;
    }
    cout << root->value;
}

NODE* InitialNode(char key)
{
    NODE *p = new NODE;
    p->value = key;
    for (int i = 0; i < MAXM; i++)
        p->kids[i] = NULL;
    return p;
}

NODE* buildTree1(LNODE levelInput[], int left, int right)
{
    if (left > right)
        return NULL;
    if (left == right)
        return InitialNode(levelInput[left].value);
    else
    {
        NODE *root = InitialNode(levelInput[left].value);
        int childNo = 0;
        int i = left + 1;
        int j = right;
        int lev = levelInput[i].level;

        int k = i + 1;
        while (k <= j)
        {
            if (levelInput[k].level == lev)
            {
                root->kids[childNo++] = buildTree1(levelInput, i, k - 1);
                i = k;
            }
            k++;
        }
        root->kids[childNo] = buildTree1(levelInput, i, j);
        return root;
    }
}

LNODE levelInput[MAXN];

int main()
{
    int N;
    cin >> N;
    string st;
    for (int i = 0; i < N; i++)
    {
        cin >> st;
        int level = 0;
        char key = 'A';
        for (int j = 1; j < (int)st.length(); j++)
        {
            if (st[j] >= '0' && st[j] <='9')
            {
                level = level * 10 + st[j] - '0';
            }
            else if (st[j] >= 'A' && st[j] <= 'Z')
            {
                key = st[j];
            }
        }
        levelInput[i].level = level;
        levelInput[i].value = key;
    }
    NODE *root;
    root = buildTree1(levelInput, 0, N - 1);
    priorder(root);
    cout << endl;
}