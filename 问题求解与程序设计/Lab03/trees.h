#ifndef TREES_H
#define TREES_H
#include <queue>

typedef struct node
{
    int key;
    struct node *lchild, *rchild;
    struct node *parent;
} NODE;

void preOrder(NODE *t) // 先根遍历
{
    static int i = 0;
    if (t != NULL)
    {
        printf("%d:", i);
        printf("%d\n", t->key);
        preOrder(t->lchild);
        preOrder(t->rchild);
    }
}

void nextOrder(NODE *t) // 后根遍历
{
    static int i = 0;
    if (t != NULL)
    {
        preOrder(t->lchild);
        preOrder(t->rchild);
        printf("%d:", i);
        printf("%d\n", t->key);
    }
}

void midOrder(NODE *t) // 中根遍历
{
    static int i = 0;
    if (t != NULL)
    {
        preOrder(t->lchild);
        printf("%d:", i);
        printf("%d\n", t->key);
        preOrder(t->rchild);
    }
}

void layerOrder(NODE *t)
{
    std::queue<NODE *> que;
    if (t != NULL)
        que.push(t);
    int i = 0;
    NODE *p;
    while (!que.empty())
    {
        printf("%d:", i);
        p = que.front();
        que.pop();
        printf("%d\n", p->key);
        if (p->lchild != NULL)
            que.push(p->lchild);
        if (p->rchild != NULL)
            que.push(p->rchild);
        i++;
    }
}

NODE *search(NODE *t, int key){
    while (t != NULL && t->key != key)
    {
        if (key < t->key)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return t;
}


NODE *mini(NODE *t){
    while (t->lchild != NULL)
        t = t->lchild;
    return t;
}

NODE *maxi(NODE *t){
    while (t->rchild != NULL)
        t = t->rchild;
    return t;
}

void transplant(NODE *root, NODE *x, NODE *y){
    if (x->parent == NULL)
        root = y;
    else
    {
        if (x == x->parent->lchild)
            x->parent->lchild = y;
        else
            x->parent->rchild = y;
    }
    if (y != NULL)
        y->parent = x->parent;
}

void insert(NODE *root, NODE *x){
        NODE *y, *cp;
        y = NULL;
        cp = root;
        while (cp != NULL){
            y = cp;
            if (x->key < cp->key)
                cp = cp->lchild;
            else
                cp = cp->rchild;
        }
        x->parent = y;
        cp = x;
    }

class BST{ // binary search trees
private:
    NODE *root;
public:
    BST(int *a, int N){
        NODE *x0;
        x0 = new NODE;
        x0->key = a[0];
        x0->lchild = x0->rchild = x0->parent = NULL;
        root = x0;
        for (int i = 1; i < N; i++)
        {
            NODE *x;
            x = new NODE;
            x->key = a[i];
            x->lchild = x->rchild = x->parent = NULL;
            insert(root, x);
        }
    }

    ~BST(){
        while (root != NULL)
            remove(root);
    }
    
    void remove(NODE *x){
        if (x->rchild == NULL)
            transplant(root, x, x->lchild);
        else if (x->lchild == NULL)
            transplant(root, x, x->rchild);
        else
        {
            NODE *y = mini(x->rchild);
            if (y->parent != x)
            {
                transplant(root, y, y->rchild);
                y->rchild = x->rchild;
                y->rchild->parent = y;
            }
            transplant(root, x, y);
            y->lchild = x->lchild;
            y->lchild->parent = y;
        }
        delete x;
    }

    NODE *Root(){
        return root;
    }
};

#endif