#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 5e5 + 10;

typedef struct node
{
    double key;
    int size;
    struct node *lchild, *rchild, *parent;
    bool isRed;
} NODE;

void leftRotate(NODE *&, NODE *);
void rightRotate(NODE *&, NODE *);
void RB_insert(NODE *&, NODE *);
void RB_delete(NODE *&, NODE *);
void RB_insert_fixup(NODE *&, NODE *);
void removeFixUp(NODE *&, NODE *, NODE *);
int size_update(NODE *);
NODE *search(NODE *, double);
void midorder(NODE *t);

void midorder(NODE *t)
{
    if (t == NULL)
        return;
    midorder(t->lchild);
    cout << t->key << " " << t->size << endl;
    midorder(t->rchild);
}

int smallnum(NODE *tr, double k)
{
    if (tr == NULL)
        return 0;
    NODE *p = tr;
    int sum = 0;
    while (p != NULL)
    {
        if (fabs(k - p->key) < 1e-6)
        {
            if (p->lchild != NULL)
                sum += p->lchild->size;
            break;
        }
        else if (k < p->key)
        {
            p = p->lchild;
        }
        else if (k > p->key)
        {
            sum += p->size;
            p = p->rchild;
            if (p != NULL)
                sum -= p->size;
        }
    }
    return sum;
}

int size_update(NODE *tr)
{
    if (tr == NULL)
        return 0;
    tr->size = size_update(tr->lchild) + size_update(tr->rchild) + 1;
    return tr->size;
}

NODE* search(NODE* tr, double k)
{
    if (tr == NULL)
        return NULL;
    NODE *p = tr;
    while (p != NULL && fabs(k - p->key) >= 1e-6)
    {
        if (k > p->key)
            p = p->rchild;
        else
            p = p->lchild;
    }
    return p;
}

void leftRotate(NODE* &tr, NODE *x)
{
    if (x->rchild == NULL)
        return;
    NODE *y = x->rchild;
    int ysize = y->size;
    y->size = x->size;
    x->size -= ysize;

    x->rchild = y->lchild;
    if (y->lchild != NULL)
    {
        y->lchild->parent = x;
        x->size += y->lchild->size;
    }
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
    int xsize = x->size;
    x->size = y->size;
    y->size -= xsize;

    y->lchild = x->rchild;
    if (x->rchild != NULL)
    {
        x->rchild->parent = y;
        y->size += x->rchild->size;
    }
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
        y->size += 1;
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
    if (node->lchild != NULL && node->rchild != NULL)
    {
        NODE *replace = node;
        replace = replace->rchild;
        while (replace->lchild != NULL)
        {
            replace = replace->lchild;
        }

        NODE *p = replace->parent;
        while (p != NULL)
        {
            p->size -= 1;
            p = p->parent;
        }

        if (node->parent != NULL)
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

        replace->size = replace->lchild->size + 1;
        if (replace->rchild != NULL)
            replace->size += replace->rchild->size;

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
    {
        child->parent = parent;
        // NODE *p = parent;
        // while (p != NULL)
        // {
        //     p->size -= 1;
        //     p = p->parent;
        // }
    }
    
    if (parent != NULL)
    {
        if (parent->lchild == node)
            parent->lchild = child;
        else
            parent->rchild = child;
        NODE *p = parent;
        while (p != NULL)
        {
            p->size -= 1;
            p = p->parent;
        }
    }
    else
        tr = child;

    if (color == false)
        removeFixUp(tr, child, parent);

    // if (parent == NULL)
    //     size_update(tr);
    // else
    // {
    //     size_update(parent);
    //     NODE *p = parent->parent;
    //     while(p != NULL)
    //     {
    //         p->size -= 1;
    //         p = p->parent;
    //     }
    // }

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
    void insert(double);
    void RBdelete(NODE *);
    void destroy(NODE *&);
};


void RBTree::insert(NODE *z)
{
    RB_insert(root, z);
}

void RBTree::insert(double x)
{
    NODE *p = new NODE;
    p->lchild = p->rchild = p->parent = NULL;
    p->key = x;
    p->size = 1;
    p->isRed = true;
    RB_insert(root, p);
}

void RBTree::RBdelete(NODE *z)
{
    RB_delete(root, z);
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





typedef struct point{
    double key;
    bool isRight;
    double startkey;
} POINT;

POINT ps[MAXN * 2];

bool cmp(POINT a, POINT b)
{
    return a.key < b.key;
}

int main()
{
    int N;
    cin >> N;
    double x1, x2, y1, y2;
    for (int i = 0; i < N; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        double res1 = atan2(y1, x1);
        double res2 = atan2(y2, x2);
        if (res1 > res2)
        {
            ps[i * 2].key = res1;
            ps[i * 2].isRight = true;
            ps[i * 2].startkey = res2;
            ps[i * 2 + 1].key = res2;
            ps[i * 2 + 1].isRight = false;
        } else {
            ps[i * 2].key = res2;
            ps[i * 2].isRight = true;
            ps[i * 2].startkey = res1;
            ps[i * 2 + 1].key = res1;
            ps[i * 2 + 1].isRight = false;
        }
    }
    sort(ps, ps + 2 * N, cmp);

    // for (int i = 0; i < 2 * N; i++)
    //     cout << ps[i].key << endl;

    long long ans = 0;
    RBTree rbtree;
    for (int i = 0; i < 2 * N; i++)
    {
        if (ps[i].isRight)
        {
            double lkey = ps[i].startkey;
            int n = smallnum(rbtree.Root(), lkey);
            
            ans += rbtree.Root()->size - n - 1;
            
            NODE *l = search(rbtree.Root(), lkey);
            //cout << lkey << " " << ps[i].key << endl;
            // cout << l->key << endl;
            // cout << m << " " <<  n << endl;
            rbtree.RBdelete(l);
        } else {
            rbtree.insert(ps[i].key);
        }
        // midorder(rbtree.Root());
        // cout << endl;
    }
    cout << ans << endl;
}