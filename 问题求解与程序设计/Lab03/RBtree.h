#ifndef RBTREE_H
#define RBTREE_H
#include <queue>

typedef struct node
{
    int key;
    struct node *lchild, *rchild, *parent;
    bool isRed;
} NODE;

void leftRotate(NODE *&, NODE *);
void rightRotate(NODE *&, NODE *);
void RB_insert(NODE *&, NODE *);
void RB_delete(NODE *&, NODE *);
void RB_insert_fixup(NODE *&, NODE *);
void removeFixUp(NODE *&, NODE *, NODE *);

void leftRotate(NODE* &tr, NODE *x)
{
    if (x->rchild == NULL)
        return;
    NODE *y = x->rchild;
    x->rchild = y->lchild;
    if (y->lchild != NULL)
        y->lchild->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        tr = y;
    else if (x == x->parent->lchild)
        x->parent->lchild = y;
    else if (x == x->parent->rchild)
        x->parent->rchild = y;
    y->lchild = x;
    x->parent = y;
    return;
}

void rightRotate(NODE* &tr, NODE *y)
{
    if (y->lchild == NULL)
        return;
    NODE *x = y->lchild;
    y->lchild = x->rchild;
    if (x->rchild != NULL)
        x->rchild->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL)
        tr = x;
    else if (y == y->parent->lchild)
        y->parent->lchild = x;
    else if (y == y->parent->rchild)
        y->parent->rchild = x;
    x->rchild = y;
    y->parent = x;
}

void RB_insert(NODE* &tr, NODE *z)
{
    NODE *x = tr;
    NODE *y = NULL;
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->lchild;
        else
            x = x->rchild;
    }
    z->parent = y;
    if (y == NULL)
        tr = z;
    else if (z->key < y->key)
        y->lchild = z;
    else
        y->rchild = z;
    z->lchild = z->rchild = NULL;
    z->isRed = true;
    RB_insert_fixup(tr, z);
    return;
}

void RB_insert_fixup(NODE* &tr, NODE *z1)
{
    NODE *z = z1;
    NODE *y = NULL;
    while (z->parent != NULL && z->parent->isRed == true)
    {
        if (z->parent == z->parent->parent->lchild)
        {
            y = z->parent->parent->rchild;
            // case 1: 叔父结点均为红色
            if (y != NULL && y->isRed == true)
            {
                z->parent->isRed = false;
                y->isRed = false;
                z->parent->parent->isRed = true;
                z = z->parent->parent;
            }
            // case 2: 叔结点为黑色
            else 
            {
                // case 2: 当前节点为右孩子
                if (z == z->parent->rchild)
                {
                    z = z->parent;
                    leftRotate(tr, z);
                } 
                // case 3: 当前节点为左孩子
                else 
                {
                    z->parent->isRed = false;
                    z->parent->parent->isRed = true;
                    rightRotate(tr, z->parent->parent);
                }
            }
        } else {
            y = z->parent->parent->lchild;
            // case 1: 叔父结点均为红色
            if (y != NULL && y->isRed == true)
            {
                z->parent->isRed = false;
                y->isRed = false;
                z->parent->parent->isRed = true;
                z = z->parent->parent;
            }
            // case 2: 叔结点为黑色
            else 
            {
                // case 2: 当前节点为左孩子
                if (z == z->parent->lchild)
                {
                    z = z->parent;
                    rightRotate(tr, z);
                } 
                // case 3: 当前节点为右孩子
                else 
                {
                    z->parent->isRed = false;
                    z->parent->parent->isRed = true;
                    leftRotate(tr, z->parent->parent);
                }
            }
        }
    }
    tr->isRed = false;
    return;
}

void RB_delete(NODE* &tr, NODE *node)
{
    NODE *child, *parent;
    bool color;
    if ((node->lchild != NULL) && (node->rchild != NULL))
    {
        NODE *replace = node;
        replace = replace->rchild;
        while (replace->lchild != NULL)
            replace = replace->lchild;
        
        if (node != NULL)
        {
            if (node->parent->lchild == node)
                node->parent->lchild = replace;
            else
                node->parent->rchild = replace;
        }
        else
            tr = replace;

        child = replace->rchild;
        parent = replace->parent;
        color = replace->isRed;

        if (parent == node)
            parent = replace;
        else
        {
            if (child != NULL)
                child->parent = parent;
            parent->lchild = child;

            replace->rchild = node->rchild;
            node->rchild->parent = replace;
        }

        replace->parent = node->parent;
        replace->isRed = node->isRed;
        replace->lchild = node->lchild;
        node->lchild->parent = replace;

        if (color == false)
            removeFixUp(tr, child, parent);

        delete node;
        return;
    }

    if (node->lchild != NULL)
        child = node->lchild;
    else
        child = node->rchild;

    parent = node->parent;
    color = node->isRed;

    if (child != NULL)
        child->parent = parent;
    
    if (parent != NULL)
    {
        if (parent->lchild == node)
            parent->lchild = child;
        else
            parent->rchild = child;
    }
    else
        tr = child;

    if (color == false)
        removeFixUp(tr, child, parent);
    delete node;
}

void removeFixUp(NODE* &tr, NODE* node, NODE* parent)
{
    NODE *other;

    while ((node == NULL || node->isRed == false) && node != tr)
    {
        if (parent->lchild == node)
        {
            other = parent->rchild;
            if (other->isRed == true)
            {
                other->isRed = false;
                parent->isRed = true;
                leftRotate(tr, parent);
                other = parent->rchild;
            }
            if ((other->lchild == NULL || other->lchild->isRed == false) && (other->rchild == NULL || other->rchild->isRed == false))
            {
                other->isRed = true;
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (other->rchild == NULL || other->rchild->isRed == false)
                {
                    other->lchild->isRed = false;
                    other->isRed = true;
                    rightRotate(tr, other);
                    other = parent->rchild;
                }
                other->isRed = parent->isRed;
                parent->isRed = false;
                other->rchild->isRed = false;
                leftRotate(tr, parent);
                node = tr;
                break;
            }
        }
        else
        {
            other = parent->lchild;
            if (other->isRed == true)
            {
                other->isRed = false;
                parent->isRed = true;
                rightRotate(tr, parent);
                other = parent->lchild;
            }
            if ((other->lchild == NULL || other->lchild->isRed == false) && (other->rchild == NULL || other->rchild->isRed == false))
            {
                other->isRed = true;
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (other->lchild == NULL || other->lchild->isRed == false)
                {
                    other->rchild->isRed = false;
                    other->isRed = true;
                    leftRotate(tr, other);
                    other = parent->lchild;
                }
                other->isRed = parent->isRed;
                parent->isRed = false;
                other->lchild->isRed = false;
                rightRotate(tr, parent);
                node = tr;
                break;
            }
        }
    }
    if (node != NULL)
        node->isRed = false;
}

class RBTree{
private:
    NODE *root;
public:
    RBTree();
    ~RBTree();

    NODE *Root();
    void insert(NODE *);
    void destroy(NODE *&);

    int RedNum();
    int BlackNum();
    int depth();
};

void RBTree::insert(NODE *z)
{
    RB_insert(root, z);
}

RBTree::RBTree()
{
    root = NULL;
}

RBTree::~RBTree()
{
    this->destroy(root);
}

NODE* RBTree::Root()
{
    return root;
}

void RBTree::destroy(NODE* &tree)
{
    if (tree == NULL)
        return;

    if (tree->lchild != NULL)
        destroy(tree->lchild);
    if (tree->rchild != NULL)
        destroy(tree->rchild);

    delete tree;
    tree = NULL;
}

int RBTree::BlackNum()
{
    std::queue<NODE *> que;
    int bn = 0;
    if (root != NULL)
        que.push(root);

    NODE *p;
    while (!que.empty())
    {
        p = que.front();
        que.pop();
        if (p->isRed == false)
            bn++;
        if (p->lchild != NULL)
            que.push(p->lchild);
        else
            bn++;
        if (p->rchild != NULL)
            que.push(p->rchild);
        else
            bn++;
    }
    return bn;
}

int RBTree::RedNum()
{
    std::queue<NODE *> que;
    if (root != NULL)
        que.push(root);

    NODE *p;
    int rn = 0;
    while (!que.empty())
    {
        p = que.front();
        que.pop();
        if (p->isRed == true)
            rn++;
        if (p->lchild != NULL)
            que.push(p->lchild);
        if (p->rchild != NULL)
            que.push(p->rchild);
    }
    return rn;
}


int depth(NODE* t)
{
    if (t == NULL)
        return 0;

    int d1 = depth(t->lchild);
    int d2 = depth(t->rchild);
    int max = d1 > d2 ? d1 : d2;

    return 1 + max;
}

#endif