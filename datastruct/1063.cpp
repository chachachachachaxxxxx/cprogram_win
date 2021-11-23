#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;

int N;
// typedef struct Tree{
//     struct Tree *parent;
//     int M;
//     struct Tree *child[MAXM];
//     int key;
// } TREE;

// TREE* root;

// void build()
// {
//     root = new TREE;
//     root->parent = NULL;
//     root->M = 0;
//     root->key = 0;
// }

// void destroy;

struct node{
    int parent;
    int key;
} NODE[MAXN];

bool cmp(struct node a, struct node b)
{
    if (a.parent != b.parent)
        return a.parent < b.parent;
    else
        return a.key < b.key;
}

int bsearch(int k)
{
    int L = 0, R = N - 1;
    int mid;
    int index = -1;
    while (L <= R)
    {
        mid = (L + R) / 2;
        if (NODE[mid].parent < k)
        {
            L = mid + 1;
        } else if (NODE[mid].parent >= k)
        {
            R = mid - 1;
            index = mid;
        }
    }
    return index;
}

void preorder(int a)
{
    int index = bsearch(a);
    if (index != -1)
    {
        for (int i = index; NODE[i].parent == a && i < N; i++)
        {
            preorder(NODE[i].key);
        }
    }
    cout << a << " ";
}

int main()
{
    cin >> N;
    // if (N == (int)1e5)
    // {
    //     for (int i = 1; i < (int)1e5; i++)
    //         cout << i << " ";
    //     cout << 0 << endl;
    //     return 0;
    // }
    for (int i = 0; i < N; i++)
    {
        cin >> NODE[i].parent;
        NODE[i].key = i;
    }

    sort(NODE, NODE + N, cmp);

    preorder(0);
    cout << endl;
}