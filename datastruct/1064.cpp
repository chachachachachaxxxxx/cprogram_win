#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAXN = 26;

typedef struct node{
    struct node *parent;
    vector<struct node *> sons;
    char key;
} NODE;

int N;
NODE *root;

void build()
{
    root = new NODE;
    root->parent = NULL;
}

void preIn(NODE *root)
{
    cin >> st;
    
}

int main()
{
    cin >> N;
    string st;
    int layer = 0;
    int j;
    char key;
    build();

    NODE *parent = root;
    int player = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> st;
        layer = 0;
        j = 1;
        for (; st[j] != ','; j++)
        {
            layer = layer * 10 + st[j] - '0';
        }
        key = st[j + 1];

        if (layer == 0)
        {
            root->key = key;
            continue;
        }

        NODE *k = new NODE;
        k->key = key;

        if (player < layer)
        {
            k->parent = parent;
            parent->sons.push_back(k);
        }
    }

}