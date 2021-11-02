#include <iostream>
using namespace std;

typedef struct node
{
    int key;
    int p;
    int m;
    int v;
    int o;
    struct node *left, *right, *parent;
    bool isRed;
} NODE;

NODE *nil = new NODE;

void leftRotate(NODE *&, NODE *);
void rightRotate(NODE *&, NODE *);
void RB_insert(NODE *&, NODE *);
void RB_delete(NODE *&, NODE *);
void RB_insert_fixup(NODE *&, NODE *);
void removeFixUp(NODE *&, NODE *, NODE *);
NODE *serach(NODE *, int, int);

void nilInit()
{
    nil->isRed = false;
    nil->key = 0;
    nil->left = nil->right = nil->parent = NULL;
    nil->p = nil->v = nil->m = nil->o = 0;
}

int max(int a,int b,int c)  
{  
    if(a>=b && a>=c)  
        return a;  
    else if(b>=c)  
        return b;  
    else  
        return c;  
}  

// void updateVOM(node *x)  
// {  
//     while(x != nil)  
//     {  
//         x->v = x->left->v + x->p + x->right->v;  
//         x->m = max(x->left->m,  
//             x->left->v + x->p,  
//             x->left->v + x->p + x->right->m);
//         if(x->m == x->left->v + x->p + x->right->m)  
//             x->o = x->right->o;  
//         if(x->m == x->left->v + x->p)  
//             x->o = x->key; 
//         if(x->m == x->left->m)  
//             x->o = x->left->o;  
//         x = x->parent;  
//     }  
// }  

void updateVOM(NODE* z)
{
    z->v = z->p + z->left->v + z->right->v;
    z->m = max(z->left->m, z->left->v + z->p, z->left->v + z->p + z->right->m);
    if (z->m == z->left->v + z->p + z->right->m)
        z->o = z->right->o;
    if (z->m == z->left->v + z->p)
        z->o = z->key;
    if (z->m == z->left->m)
        z->o = z->left->o;
}

NODE *search(NODE *tr, int key, int left)
{
    NODE *p = tr;
    while (p != nil)
    {
        if (p->key < key)
            p = p->right;
        else if (p->key > key)
            p = p->left;
        else
        {
            if (left > 0)
            {
                if (p->p > 0)
                    return p;
                else
                    p = p->left;
            }
            else if (left < 0)
            {
                if (p->p < 0)
                    return p;
                else
                    p = p->right;
            }
        }
    }
    return p;
}

void leftRotate(NODE* &tr, NODE *x)
{
    if (x->right == nil)
        return;
    NODE *y = x->right;
    x->right = y->left;
    if (y->left != nil)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nil)
        tr = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    y->left = x;
    x->parent = y;

    updateVOM(x);
    updateVOM(y);
    return;
}

void rightRotate(NODE* &tr, NODE *y)
{
    if (y->left == nil)
        return;
    NODE *x = y->left;
    y->left = x->right;
    if (x->right != nil)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == nil)
        tr = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    x->right = y;
    y->parent = x;

    updateVOM(y);
    updateVOM(x);
}

void RB_insert(NODE* &tr, NODE *z)
{
    NODE *x = tr;
    NODE *y = nil;
    while (x != nil)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else if (z->key > x->key)
            x = x->right;
        else
        {
            if (z->p < x->p)
                x = x->right;
            else if (z->p > x->p)
                x = x->left;
        }
    }
    z->parent = y;
    if (y == nil)
        tr = z;
    else if (z->key < y->key)
        y->left = z;
    else if (z->key > y->key)
        y->right = z;
    else
    {
        if (z->p < y->p)
            y->right = z;
        else
            y->left = z;
    }
        
    z->left = z->right = nil;
    z->isRed = true;

    RB_insert_fixup(tr, z);

    NODE *p = z;
    while (p != nil)
    {
        updateVOM(p);
        p = p->parent;
    }
    // updateVOM(z);
    return;
}

void RB_insert_fixup(NODE* &tr, NODE *z1)
{
    NODE *z = z1;
    NODE *y = nil;
    while (z->parent != nil && z->parent->isRed == true)
    {
        if (z->parent == z->parent->parent->left)
        {
            y = z->parent->parent->right;
            // case 1: 叔父结点均为红色
            if (y != nil && y->isRed == true)
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
                if (z == z->parent->right)
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
            y = z->parent->parent->left;
            // case 1: 叔父结点均为红色
            if (y != nil && y->isRed == true)
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
                if (z == z->parent->left)
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
    if ((node->left != nil) && (node->right != nil))
    {
        NODE *replace = node;
        replace = replace->right;
        while (replace->left != nil)
            replace = replace->left;
        
        if (node->parent != nil)
        {
            if (node->parent->left == node)
                node->parent->left = replace;
            else
                node->parent->right = replace;
        }
        else
            tr = replace;

        child = replace->right;
        parent = replace->parent;
        color = replace->isRed;

        if (parent == node)
            parent = replace;
        else
        {
            if (child != nil)
                child->parent = parent;
            parent->left = child;

            replace->right = node->right;
            node->right->parent = replace;
        }

        replace->parent = node->parent;
        replace->isRed = node->isRed;
        replace->left = node->left;
        node->left->parent = replace;

        if (color == false)
            removeFixUp(tr, child, parent);

        delete node;
        return;
    }

    if (node->left != nil)
        child = node->left;
    else
        child = node->right;

    parent = node->parent;
    color = node->isRed;

    if (child != nil)
        child->parent = parent;
    
    if (parent != nil)
    {
        if (parent->left == node)
            parent->left = child;
        else
            parent->right = child;
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

    while (node->isRed == false && node != tr)
    {
        if (parent->left == node)
        {
            other = parent->right;
            if (other->isRed == true)
            {
                other->isRed = false;
                parent->isRed = true;
                leftRotate(tr, parent);
                other = parent->right;
            }
            if ((other->left == nil || other->left->isRed == false) && (other->right == nil || other->right->isRed == false))
            {
                other->isRed = true;
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (other->right == nil || other->right->isRed == false)
                {
                    other->left->isRed = false;
                    other->isRed = true;
                    rightRotate(tr, other);
                    other = parent->right;
                }
                other->isRed = parent->isRed;
                parent->isRed = false;
                other->right->isRed = false;
                leftRotate(tr, parent);
                node = tr;
                break;
            }
        }
        else
        {
            other = parent->left;
            if (other->isRed == true)
            {
                other->isRed = false;
                parent->isRed = true;
                rightRotate(tr, parent);
                other = parent->left;
            }
            if ((other->left == nil || other->left->isRed == false) && (other->right == nil || other->right->isRed == false))
            {
                other->isRed = true;
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (other->left == nil || other->left->isRed == false)
                {
                    other->right->isRed = false;
                    other->isRed = true;
                    leftRotate(tr, other);
                    other = parent->left;
                }
                other->isRed = parent->isRed;
                parent->isRed = false;
                other->left->isRed = false;
                rightRotate(tr, parent);
                node = tr;
                break;
            }
        }
    }
    updateVOM(node);
    // NODE *p = node;
    // while (p != nil)
    // {
    //     updateVOM(p);
    //     p = p->parent;
    // }
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
    void insert(int key, int left);
    void rbDelete(NODE *);
    void destroy(NODE *&);

};

void RBTree::rbDelete(NODE *z)
{
    RB_delete(root, z);
}

void RBTree::insert(int key, int left)
{
    NODE *p = new NODE;
    p->isRed = true;
    p->left = p->right = p->parent = nil;
    p->m = 0;
    p->o = key;
    p->key = key;
    p->v = p->p = left;
    RB_insert(root, p);
}

void RBTree::insert(NODE *z)
{
    RB_insert(root, z);
}

RBTree::RBTree()
{
    root = nil;
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
    if (tree == nil)
        return;

    if (tree->left != nil)
        destroy(tree->left);
    if (tree->right != nil)
        destroy(tree->right);

    delete tree;
    tree = nil;
}

void midorder(NODE *t)
{
    if (t == nil)
        return;
    midorder(t->left);
    cout << t->key << " " << t->p << " " << t->v << " " << t->m << " " << t->o <<endl;
    midorder(t->right);
}


int main()
{
    nilInit();
    int N, op, le, ri;
    cin >> N;
    RBTree tr;
    for (int i = 0; i < N; i++)
    {
        cin >> op;
        if (op == 3)
        {
            cout << tr.Root()->o << endl;
        } 
        else if (op == 1)
        {
            cin >> le >> ri;
            NODE *p = search(tr.Root(), le, 1);
            if (p != nil)
            {
                p->p++;
                updateVOM(p);
            } else {
                tr.insert(le, 1);
            }
            p = search(tr.Root(), ri, -1);
            //cout << p->key << p->p << p->m << p->o << endl;
            if (p != nil)
            {
                p->p--;
            while (p != nil)
            {
                updateVOM(p);
                p = p->parent;
            }
            } else {
                tr.insert(ri, -1);
            }
        } 
        else
        {
            cin >> le >> ri;
            NODE *p = search(tr.Root(), le, 1);
            p->p--;
            while (p != nil)
            {
                updateVOM(p);
                p = p->parent;
            }
            // if (p->p == 0)
            //     tr.rbDelete(p);
                

            p = search(tr.Root(), ri, -1);
            //cout << p->key << p->p << p->m << p->o << endl;
            p->p++;

            while (p != nil)
            {
                updateVOM(p);
                p = p->parent;
            }
            // if (p->p == 0)
            //     tr.rbDelete(p)
        }
        // midorder(tr.Root());
        // cout << endl;
    }
}
