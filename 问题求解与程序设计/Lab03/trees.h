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
    //static int i = 0;
    if (t != NULL)
    {
        //printf("%d:", i++);
        printf("%d\n", t->key);
        preOrder(t->lchild);
        preOrder(t->rchild);
    }
}

void nextOrder(NODE *t) // 后根遍历
{
    //static int i = 0;
    if (t != NULL)
    {
        nextOrder(t->lchild);
        nextOrder(t->rchild);
        //printf("%d:", i++);
        printf("%d\n", t->key);
    }
}

void midOrder(NODE *t) // 中根遍历
{
    //static int i = 0;
    if (t != NULL)
    {
        midOrder(t->lchild);
        //printf("%d:", i++);
        printf("%d\n", t->key);
        midOrder(t->rchild);
    }
}

void layerOrder(NODE *t)
{
    std::queue<NODE *> que;
    if (t != NULL)
        que.push(t);
    //int i = 0;
    NODE *p;
    while (!que.empty())
    {
        //printf("%d:", i);
        p = que.front();
        que.pop();
        printf("%d\n", p->key);
        if (p->lchild != NULL)
            que.push(p->lchild);
        if (p->rchild != NULL)
            que.push(p->rchild);
        //i++;
    }
}

NODE *search(NODE *t, int key){
    NODE *p = t;
    while (p != NULL && p->key != key)
    {
        if (key < p->key)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return p;
}


NODE *mini(NODE *t){
    NODE *p = t;
    while (p != NULL)
        p = p->lchild;
    return p;
}

NODE *maxi(NODE *t){
    NODE *p = t;
    while (p != NULL)
        p = p->rchild;
    return p;
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
    // if (root == NULL)
    // {
    //     root->key = x->key;
    //     root->parent = root->lchild = root->rchild = NULL;
    //     return;
    // }
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
    if (cp == y->lchild)
        y->lchild = x;
    else
        y->rchild = x;
    x->parent = y;
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
        // root = NULL;
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