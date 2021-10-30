#include <stdio.h>      
#include <stdlib.h>      
#define RED 1      
#define BLACK 0      
      
typedef struct RBTreeNode      
{      
    int key;      
    int color;  
    int pp;//左端点1，右端点-1  
    int v;//子树所有端点P值之和  
    int m;//当前节点S(1,i)最大值  
    int o;//最大值对应的节点key  
    RBTreeNode *p;      
    RBTreeNode *left;      
    RBTreeNode *right;      
}RBT,*pRBT;      
      
pRBT nil=(pRBT)malloc(sizeof(RBT));      
int bh=0;    
    
void initNil()      
{      
    nil->key=-1;      
    nil->color=BLACK;      
    nil->p=NULL;      
    nil->left=NULL;      
    nil->right=NULL;  
    nil->pp=0;  
    nil->m=0;  
    nil->o=-1;  
    nil->v=0;  
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
  
void updateVOM(pRBT z)  
{  
    z->v=z->left->v+z->pp+z->right->v;  
    z->m=max(z->left->m,z->left->v+z->pp,z->left->v+z->pp+z->right->m);  
    if(z->m==z->left->m)  
        z->o=z->left->o;  
    else if(z->m==z->left->v+z->pp)  
        z->o=z->key;  
    else  
        z->o=z->right->o;  
}  
      
void leftRotate(pRBT *root,pRBT x)      
{      
    //左旋要有右子树      
    if(x->right==nil)      
        return;      
    pRBT y=x->right;      
    x->right=y->left;      
    if(y->left != nil)      
        y->left->p=x;      
    y->p=x->p;      
    if(x->p==nil)      
    {      
        (*root)=y;      
    }      
    else if(x == x->p->left)      
    {      
        x->p->left=y;      
    }      
    else      
    {      
        x->p->right=y;      
    }      
    y->left=x;      
    x->p=y;     
    updateVOM(x);  
    updateVOM(y);  
}      
      
void rightRotate(pRBT *root,pRBT y)      
{      
    //右旋要有左子树      
    if(y->left==nil)      
        return;      
    pRBT x=y->left;      
    y->left=x->right;      
    x->p=y->p;      
    if(x->right != nil)    
        x->right->p=y;    
    if(y->p==nil)      
    {      
        (*root)=x;      
    }      
    else if(y==y->p->left)      
    {      
        y->p->left=x;      
    }      
    else      
    {      
        y->p->right=x;      
    }      
    x->right=y;      
    y->p=x;  
    updateVOM(y);  
    updateVOM(x);  
}      
      
void rbInsertFixup(pRBT *root,pRBT z)      
{      
    while(z->p->color==RED)      
    {      
        if(z->p==z->p->p->left)      
        {      
            pRBT y=z->p->p->right;      
            if(y->color==RED)      
            {      
                z->p->color=BLACK;      
                y->color=BLACK;      
                z->p->p->color=RED;      
                z=z->p->p;      
            }      
            else       
            {      
                if(z==z->p->right)      
                {      
                    z=z->p;      
                    leftRotate(root,z);      
                }      
                z->p->color=BLACK;      
                z->p->p->color=RED;      
                rightRotate(root,z->p->p);      
            }      
        }      
        else      
        {      
            pRBT y=z->p->p->left;      
            if(y->color==RED)      
            {      
                z->p->color=BLACK;      
                y->color=BLACK;      
                z->p->p->color=RED;      
                z=z->p->p;      
            }      
            else       
            {      
                if(z==z->p->left)      
                {      
                    z=z->p;      
                    rightRotate(root,z);      
                }      
                z->p->color=BLACK;      
                z->p->p->color=RED;      
                leftRotate(root,z->p->p);      
            }      
        }      
    }      
    if((*root)==nil || (*root)->color==RED)    
        bh++;    
    (*root)->color=BLACK;    
        
}      
      
void rbInsert(pRBT *root,int key,char c)      
{      
    pRBT z=(pRBT)malloc(sizeof(RBT));      
    z->key=key;    
	if(c=='L')  
        z->pp=1;  
    else  
        z->pp=-1;
    pRBT x=(*root);      
    pRBT y=nil;      
    while(x != nil)      
    {      
        y=x;  
		// When multiple endpoints have the same value, 
		//insert all the left endpoints with that value before inserting any  of the right endpoints with that value
		if(z->key<x->key || (z->key==x->key && z->pp>x->pp))      
        {      
            x=x->left;      
        }      
        else      
        {      
            x=x->right;      
        }      
    }      
    z->p=y;      
    if(y==nil)      
    {      
        (*root)=z;      
    }      
	// When multiple endpoints have the same value, 
	//insert all the left endpoints with that value before inserting any  of the right endpoints with that value
    else if(z->key<y->key || (z->key==y->key && z->pp>y->pp))      
    {      
        y->left=z;      
    }      
    else      
    {      
        y->right=z;      
    }      
    z->left=nil;      
    z->right=nil;      
    z->color=RED;  
      
    pRBT u=z;  
    while(u != nil)  
    {  
        updateVOM(u);  
        u=u->p;  
    }  
    rbInsertFixup(root,z);      
}    
    
void rbTransplant(pRBT *root,pRBT u,pRBT v)    
{    
    if(u->p==nil)    
        (*root)=v;    
    else if(u==u->p->left)    
        u->p->left=v;    
    else    
        u->p->right=v;    
    v->p=u->p;    
}    
    
pRBT treeMinimum(pRBT root)    
{    
    if(root==nil)    
        return root;    
    pRBT x=root;    
    while(x->left!=nil)    
    {    
        x=x->left;    
    }    
    return x;    
}    
    
void rbDeleteFixup(pRBT *root,pRBT x)    
{    
    while(x != *root && x->color==BLACK)    
    {    
        if(x==x->p->left)    
        {    
            pRBT w=x->p->right;    
            if(w->color==RED)    
            {    
                w->color=BLACK;    
                x->p->color=RED;    
                leftRotate(root,x->p);    
                w=x->p->right;    
            }    
            if(w->left->color==BLACK && w->right->color==BLACK)    
            {    
                w->color=RED;    
                x=x->p;    
                if(x==*root)    
                    bh--;    
            }    
            else    
            {    
                if(w->right->color == BLACK)    
                {    
                    w->left->color=BLACK;    
                    w->color=RED;    
                    rightRotate(root,w);    
                    w=x->p->right;    
                }    
                w->color=x->p->color;    
                x->p->color=BLACK;    
                w->right->color=BLACK;    
                leftRotate(root,x->p);    
                x=(*root);    
            }    
        }    
        else    
        {    
            pRBT w=x->p->left;    
            if(w->color==RED)    
            {    
                w->color=BLACK;    
                x->p->color=RED;    
                rightRotate(root,x->p);    
                w=x->p->left;    
            }    
            if(w->left->color==BLACK && w->right->color==BLACK)    
            {    
                w->color=RED;    
                x=x->p;    
            }    
            else    
            {    
                if(w->left->color == BLACK)    
                {    
                    w->right->color=BLACK;    
                    w->color=RED;    
                    leftRotate(root,w);    
                    w=x->p->left;    
                }    
                w->color=x->p->color;    
                x->p->color=BLACK;    
                w->left->color=BLACK;    
                rightRotate(root,x->p);    
                x=(*root);    
            }    
        }    
    }    
    pRBT u=x;  
    while(u != nil)  
    {  
        updateVOM(u);  
        u=u->p;  
    }  
    x->color=BLACK;    
}    
    
void rbDelete(pRBT *root,pRBT z)    
{    
    pRBT y=z,x;    
    int yOrigColor=y->color;    
    if(z->left==nil)    
    {    
        x=z->right;    
        rbTransplant(root,z,x);    
    }    
    else if(z->right==nil)    
    {    
        x=z->left;    
        rbTransplant(root,z,x);    
    }    
    else    
    {    
        y=treeMinimum(z->right);    
        yOrigColor=y->color;    
        x=y->right;    
        if(y->p==z)    
        {    
            x->p=y;    
        }    
        else    
        {    
            rbTransplant(root,y,x);    
            y->right=z->right;    
            y->right->p=y;    
        }    
        rbTransplant(root,z,y);    
        y->left=z->left;    
        y->left->p=y;    
        y->color=z->color;    
        if(yOrigColor==BLACK)    
            rbDeleteFixup(root,x);    
    }    
}    
    
void preTrav(pRBT root,char c)    
{    
    if(root==nil)    
        return;    
    else    
    {    
		printf("key=%d,o=%d,m=%d，pp=%d,v=%d ",root->key,root->o,root->m,root->pp,root->v);    
        if(root->color==BLACK)    
            printf("%s ","黑");    
        else    
            printf("%s ","红");    
        printf("%c ",c);    
        printf("\n");  
        preTrav(root->left,'L');    
        preTrav(root->right,'R');    
    }    
}    
    
pRBT treeSearch(pRBT root,int key)    
{    
    pRBT x=root;    
    while(x!=nil && x->key!=key)    
    {    
        if(key<x->key)    
            x=x->left;    
        else if (key > x->key)    
            x=x->right;
        else
        {
            
        }    
    }    
    return x;    
}    
    
int main()    
{    
    initNil();    
    pRBT root=nil;
    int N;
    cin >> N;
    int op;
    int l, r;
    for (int i = 0; i < N; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> l >> r;
            rbInsert(&root, l, "L");
            rbInsert(&root, r, "r");
        } 
        else if (op == 2)
        {
            cout << root.o << endl;
        }
        else if (op == 3)
        {

        }
    }
}