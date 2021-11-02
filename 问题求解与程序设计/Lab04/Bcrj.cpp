#include <bits/stdc++.h>
using namespace std;  
#define BLACK 0  
#define RED 1  
#define INIT -81247812

typedef struct RBNODE  
{  
    RBNODE *left;  
    RBNODE *right;  
    RBNODE *parent;  
    int key;  
    bool color;  
    int p;//1：左端点；-1：区间右端点  
    //附加信息  
    int cl{0} ;
    int cr{0} ;
    int v;    //以x为根的所有结点的p值之和
    int m;    //MAX(SUM([left[x], i))  
    int o;    //以x为根的所有结点中的最大覆盖点  
} RBNODE;  

RBNODE *root;//根结点  
RBNODE *NIL;//哨兵  

void init() 
{
    NIL = new RBNODE ;
    NIL->color = BLACK ;
    NIL->cl = 0 ;
    NIL->cr = 0 ;
    NIL->v = 0 ;
    NIL->p = 0 ;
    NIL->m = INIT;
    NIL->o = INIT;
    root = NIL ;
}

void init_RBNODE(RBNODE* a , int val , int sign)
{
    a->key = val ;
    a->left = NIL ;
    a->right = NIL ;
    a->parent = NIL ;
    a->color = RED ;
    a->o = val ;
    a->m = 0 ;
    if(sign == 1) a->cl = 1 ;
    else a->cr = -1 ;
}

int max(int a, int b, int c)  
{  
    if(a > b)  
        return a > c ? a : c;  
    else  
        return b > c ? b : c;  
}  

void Maintaining(RBNODE *x)  
{  
    while(x != NIL)  
    {  
        x->p = x->cl + x->cr ;
        x->v = x->left->v + x->p + x->right->v;      //维护v值

        x->m = max(x->left->m,  
            x->left->v + x->cl,  
            x->left->v + x->p + x->right->m);  

        if(x->m == x->left->m)  
            x->o = x->left->o;  
        else if(x->m == x->left->v + x->cl)  
            x->o = x->key ;  
        else  
            x->o = x->right->o ;  
        x = x->parent;  
    }  
}  

void Maintain(RBNODE *x)  
{  
    x->p = x->cl + x->cr ;
    x->v = x->left->v + x->p + x->right->v;      //维护v值

    x->m = max(x->left->m,  
        x->left->v + x->cl,  
        x->left->v + x->p + x->right->m);  

    if(x->m == x->left->m)  
        x->o = x->left->o;  
    else if(x->m == x->left->v + x->cl)  
        x->o = x->key ;  
    else  
        x->o = x->right->o ;  
    x = x->parent;  
}  

void Left_Rotate(RBNODE *x)  
{  
    RBNODE *y = x->right;  
    x->right = y->left;  
    if(y->left != NIL)  
        y->left->parent = x;  
    y->parent = x->parent;  
    if(x->parent == NIL)
        root = y;  
    else if(x == x->parent->left)  
        x->parent->left = y;  
    else   
        x->parent->right = y;  
    y->left = x;  
    x->parent = y;  
    Maintain(x);  
    Maintain(y);  
}  

void Right_Rotate(RBNODE *x)  
{  
    RBNODE *y = x->left;  
    x->left = y->right;  
    if(y->right != NIL)  
        y->right->parent = x;  
    y->parent = x->parent;  
    if(x->parent == NIL)  
        root = y;  
    else if(x == x->parent->right)  
        x->parent->right = y;  
    else   
        x->parent->left = y;  
    y->right = x;  
    x->parent = y;  
    Maintain(x);  
    Maintain(y);  
}  

void RB_Insert_Fixup(RBNODE *z)  
{  
    RBNODE *y;  
    //唯一需要调整的情况，就是违反性质2的时候，如果不违反性质2，调整结束  
    while(z != root && z->parent->color == RED)  
    {  
        //parent[z]是左孩子时，有三种情况  
        if(z->parent == z->parent->parent->left)  
        {  
            //令y是z的叔结点  
            y = z->parent->parent->right;  
            //第一种情况，z的叔叔y是红色的  
            if(y != NIL && y->color == RED)  
            {  
                //将parent[z]和y都着为黑色以解决z和parent[z]都是红色的问题  
                z->parent->color = BLACK;  
                y->color = BLACK;  
                //将parent[parent[z]]着为红色以保持性质5  
                z->parent->parent->color = RED;  
                //把parent[parent[z]]当作新增的结点z来重复while循环  
                z = z->parent->parent;  
            }  
            else  
            {  
                //第二种情况：z的叔叔是黑色的，且z是右孩子  
                if(z == z->parent->right)  
                {  
                    //对parent[z]左旋，转为第三种情况  
                    z = z->parent;  
                    Left_Rotate(z);  
                }  
                //第三种情况：z的叔叔是黑色的，且z是左孩子  
                //交换parent[z]和parent[parent[z]]的颜色，并右旋  
                z->parent->color = BLACK;  
                z->parent->parent->color = RED;  
                Right_Rotate(z->parent->parent);  
            }  
        }  
        else  
        {  
            y = z->parent->parent->left;  
            if(y != NIL && y->color == RED)  
            {  
                z->parent->color = BLACK;  
                y->color = BLACK;  
                z->parent->parent->color = RED;  
                z = z->parent->parent;  
            }  
            else  
            {  
                if(z == z->parent->left)  
                {  
                    z = z->parent;  
                    Right_Rotate(z);  
                }  
                z->parent->color = BLACK;  
                z->parent->parent->color = RED;  
                Left_Rotate(z->parent->parent);  
            }  
        }  
    }  
    root->color = BLACK;  
}  

void RB_Insert(RBNODE *z)  
{  
    RBNODE *y = NIL, *x = root;  
    while(x != NIL)  
    {  
        y = x;  
        if(z->key < x->key)  
            x = x->left;  
        else
            x = x->right;
    }  
    z->parent = y;  
    if(y == NIL)  
        root = z;  
    else if(z->key < y->key)  
        y->left = z;  
    else  
        y->right = z;  
    Maintaining(z); 
    RB_Insert_Fixup(z);  
}  

RBNODE *RB_Search(RBNODE *x, int k)    
{    
    while(x != NIL && x->key != k) {
        if(x->key > k) {
            x = x->left ;
        } else {
            x = x->right ;
        }
    }
    return x ;
}   

int Find_Pom()  
{  
    return root->o ;  
}  

void midorder(RBNODE *t)
{
    if (t == NIL)
        return;
    midorder(t->left);
    cout << t->key << " " << t->p << " " << t->v << " " << t->m << " " << t->o <<endl;
    midorder(t->right);
}

int main()  
{  
    init() ;  
    int start, end ;  
    int cmd , n ;
    RBNODE *m , *z ;  
    cin >> n ;
    for(int i = 0 ; i < n ; i++)  
    {  
        cin >> cmd ;  
        if(cmd == 1) {
            cin >> start >> end ;
            m = RB_Search(root , start) ;
            z = RB_Search(root , end) ;
            if(m == NIL) {
                m = new RBNODE ;
                init_RBNODE(m , start , 1) ;
                RB_Insert(m) ;
            } else {
                m->cl ++ ; Maintaining(m) ;
            }
            if(z == NIL) {
                z = new RBNODE ;
                init_RBNODE(z , end , -1) ;
                RB_Insert(z) ;
            } else {
                z->cr -- ;  Maintaining(z) ;
            }
        }  
        else if(cmd == 2) {
            cin >> start >> end;  
            m = RB_Search(root, start);  
            m->cl -- ; Maintaining(m) ;
            z = RB_Search(root, end);   
            z->cr ++ ; Maintaining(z) ;
        }
        else if(cmd == 3) {
            cout << Find_Pom() << endl ;
        }
        midorder(root);
        cout << endl;
    }  
    return 0;  
}  