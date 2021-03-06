#include <iostream>  
using namespace std;  
  
#define BLACK 0  
#define RED 1  
  
//红黑树结点结构  
struct node  
{  
    //红黑树的基础结构  
    node *left;  
    node *right;  
    node *parent;  
    int key;  
    bool color;  
    int p;//1：左端点；-1：区间右端点  
    //附加信息  
    int v;  
    int m;  
    int o;  
    node(node *init, int k)  
        :left(init),right(init),parent(init),key(k),color(BLACK),v(0),m(0),o(k){}  
};  
//红黑树结构  
struct Red_Black_Tree  
{  
    node *root;//根结点  
    node *nil;//哨兵  
    Red_Black_Tree(){nil = new node(NULL, -1);root = nil;};  
};  
int max(int a, int b, int c)  
{  
    if(a > b)  
        return a > c ? a : c;  
    else  
        return b > c ? b : c;  
}  
//对附加信息的维护  
void Maintaining(node *x)  
{  
    while(x->key >= 0)  
    {  
        x->v = x->left->v + x->p + x->right->v;  
        x->m = max(x->left->m,  
            x->left->v + x->p,  
            x->left->v + x->p + x->right->m);  
        if(x->left->key != -1 && x->m == x->left->m)  
            x->o = x->left->o;  
        else if(x->right->key != -1 && x->m == x->left->v + x->p + x->right->m)  
            x->o = x->right->o;  
        else  
            x->o = x->key;  
        x = x->parent;  
    }  
}  
//左旋，令y = x->right, 左旋是以x和y之间的链为支轴进行旋转  
//涉及到的结点包括：x,y,y->left，令node={p,l,r},具体变化如下：  
//x={x->parent,x->left,y}变为{y,x->left,y->left}  
//y={x,y->left,y->right}变为{x->parent,x,y->right}  
//y->left={y,y->left->left,y->left->right}变为{x,y->left->left,y->left->right}  
void Left_Rotate(Red_Black_Tree *T, node *x)  
{  
    //令y = x->right  
    node *y = x->right;  
    //按照上面的方式修改三个结点的指针，注意修改指针的顺序  
    x->right = y->left;  
    if(y->left != T->nil)  
        y->left->parent = x;  
    y->parent = x->parent;  
    if(x->parent == T->nil)//特殊情况：x是根结点  
        T->root = y;  
    else if(x == x->parent->left)  
        x->parent->left = y;  
    else   
        x->parent->right = y;  
    y->left = x;  
    x->parent = y;  
    //对附加信息的维护  
    Maintaining(x);  
    Maintaining(y);  
}  
//右旋，令y = x->left, 左旋是以x和y之间的链为支轴进行旋转  
//旋转过程与上文类似  
void Right_Rotate(Red_Black_Tree *T, node *x)  
{  
    node *y = x->left;  
    x->left = y->right;  
    if(y->right != T->nil)  
        y->right->parent = x;  
    y->parent = x->parent;  
    if(x->parent == T->nil)  
        T->root = y;  
    else if(x == x->parent->right)  
        x->parent->right = y;  
    else   
        x->parent->left = y;  
    y->right = x;  
    x->parent = y;  
    //对附加信息的维护  
    Maintaining(x);  
    Maintaining(y);  
}  
//红黑树调整  
void RB_Insert_Fixup(Red_Black_Tree *T, node *z)  
{  
    node *y;  
    //唯一需要调整的情况，就是违反性质2的时候，如果不违反性质2，调整结束  
    while(z->parent->color == RED)  
    {  
        //parent[z]是左孩子时，有三种情况  
        if(z->parent == z->parent->parent->left)  
        {  
            //令y是z的叔结点  
            y = z->parent->parent->right;  
            //第一种情况，z的叔叔y是红色的  
            if(y->color == RED)  
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
                    Left_Rotate(T, z);  
                }  
                //第三种情况：z的叔叔是黑色的，且z是左孩子  
                //交换parent[z]和parent[parent[z]]的颜色，并右旋  
                z->parent->color = BLACK;  
                z->parent->parent->color = RED;  
                Right_Rotate(T, z->parent->parent);  
            }  
        }  
        //parent[z]是右孩子时，有三种情况，与上面类似  
        else if(z->parent == z->parent->parent->right)  
        {  
            y = z->parent->parent->left;  
            if(y->color == RED)  
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
                    Right_Rotate(T, z);  
                }  
                z->parent->color = BLACK;  
                z->parent->parent->color = RED;  
                Left_Rotate(T, z->parent->parent);  
            }  
        }  
    }  
    //根结点置为黑色  
    T->root->color = BLACK;  
}  
//插入一个结点  
void RB_Insert(Red_Black_Tree *T, node *z)  
{  
    node *y = T->nil, *x = T->root;  
    //找到应该插入的位置，与二叉查找树的插入相同  
    while(x != T->nil)  
    {  
        y = x;  
        if(z->key < x->key)  
            x = x->left;  
        else if(z->key > x->key)  
            x = x->right;  
    }  
    z->parent = y;  
    if(y == T->nil)  
        T->root = z;  
    else if(z->key < y->key)  
        y->left = z;  
    else  
        y->right = z;  
    z->left = T->nil;  
    z->right = T->nil;  
    //将新插入的结点转为红色  
    z->color = RED;  
    //从新插入的结点开始，向上调整  
    RB_Insert_Fixup(T, z);  
    Maintaining(z);  
}  
//对树进行调整，x指向一个红黑结点，调整的过程是将额外的黑色沿树上移  
void RB_Delete_Fixup(Red_Black_Tree *T, node *x)  
{  
    node *w;  
    //如果这个额外的黑色在一个根结点或一个红结点上，结点会吸收额外的黑色，成为一个黑色的结点  
    while(x != T->root && x->color == BLACK)  
    {  
        //若x是其父的左结点（右结点的情况相对应）  
        if(x == x->parent->left)  
        {  
            //令w为x的兄弟，根据w的不同，分为三种情况来处理  
            //执行删除操作前x肯定是没有兄弟的，执行删除操作后x肯定是有兄弟的  
            w = x->parent->right;  
            //第一种情况：w是红色的  
            if(w->color == RED)  
            {  
                //改变w和parent[x]的颜色  
                w->color = BLACK;  
                x->parent->color = RED;  
                //对parent[x]进行一次左旋  
                Left_Rotate(T, x->parent);  
                //令w为x的新兄弟  
                w = x->parent->right;  
                //转为2.3.4三种情况之一  
            }  
            //第二情况：w为黑色，w的两个孩子也都是黑色  
            if(w->left->color == BLACK && w->right->color == BLACK)  
            {  
                //去掉w和x的黑色  
                //w只有一层黑色，去掉变为红色，x有多余的一层黑色，去掉后恢复原来颜色  
                w->color = RED;  
                //在parent[x]上补一层黑色  
                x = x->parent;  
                //现在新x上有个额外的黑色，转入for循环继续处理  
            }  
            //第三种情况，w是黑色的,w->left是红色的,w->right是黑色的  
            else  
            {  
                if(w->right->color == BLACK)  
                {  
                    //改变w和left[x]的颜色  
                    w->left->color = BLACK;  
                    w->color = RED;  
                    //对w进行一次右旋  
                    Right_Rotate(T, w);  
                    //令w为x的新兄弟  
                    w = x->parent->right;  
                    //此时转变为第四种情况  
                }  
                //第四种情况：w是黑色的,w->left是黑色的,w->right是红色的  
                //修改w和parent[x]的颜色  
                w->color =x->parent->color;  
                x->parent->color = BLACK;  
                w->right->color = BLACK;  
                //对parent[x]进行一次左旋  
                Left_Rotate(T, x->parent);  
                //此时调整已经结束，将x置为根结点是为了结束循环  
                x = T->root;  
            }  
        }  
        //若x是其父的左结点（右结点的情况相对应）  
        else if(x == x->parent->right)  
        {  
            //令w为x的兄弟，根据w的不同，分为三种情况来处理  
            //执行删除操作前x肯定是没有兄弟的，执行删除操作后x肯定是有兄弟的  
            w = x->parent->left;  
            //第一种情况：w是红色的  
            if(w->color == RED)  
            {  
                //改变w和parent[x]的颜色  
                w->color = BLACK;  
                x->parent->color = RED;  
                //对parent[x]进行一次左旋  
                Right_Rotate(T, x->parent);  
                //令w为x的新兄弟  
                w = x->parent->left;  
                //转为2.3.4三种情况之一  
            }  
            //第二情况：w为黑色，w的两个孩子也都是黑色  
            if(w->right->color == BLACK && w->left->color == BLACK)  
            {  
                //去掉w和x的黑色  
                //w只有一层黑色，去掉变为红色，x有多余的一层黑色，去掉后恢复原来颜色  
                w->color = RED;  
                //在parent[x]上补一层黑色  
                x = x->parent;  
                //现在新x上有个额外的黑色，转入for循环继续处理  
            }  
            //第三种情况，w是黑色的,w->right是红色的,w->left是黑色的  
            else  
            {  
                if(w->left->color == BLACK)  
                {  
                    //改变w和right[x]的颜色  
                    w->right->color = BLACK;  
                    w->color = RED;  
                    //对w进行一次右旋  
                    Left_Rotate(T, w);  
                    //令w为x的新兄弟  
                    w = x->parent->left;  
                    //此时转变为第四种情况  
                }  
                //第四种情况：w是黑色的,w->right是黑色的,w->left是红色的  
                //修改w和parent[x]的颜色  
                w->color =x->parent->color;  
                x->parent->color = BLACK;  
                w->left->color = BLACK;  
                //对parent[x]进行一次左旋  
                Right_Rotate(T, x->parent);  
                //此时调整已经结束，将x置为根结点是为了结束循环  
                x = T->root;  
            }  
        }  
    }  
    //吸收了额外的黑色  
    x->color = BLACK;  
}  
//找最小值     
node *Tree_Minimum(Red_Black_Tree *T, node *x)    
{    
    //只要有比当前结点小的结点     
    while(x->left != T->nil)    
        x = x->left;    
    return x;    
}   
//查找中序遍历下x结点的后继，后继是大于key[x]的最小的结点     
node *Tree_Successor(Red_Black_Tree *T, node *x)    
{    
    //如果有右孩子     
    if(x->right != T->nil)    
        //右子树中的最小值     
        return Tree_Minimum(T, x->right);    
    //如果x的右子树为空且x有后继y，那么y是x的最低祖先结点，且y的左儿子也是     
    node *y = x->parent;    
    while(y != NULL && x == y->right)    
    {    
        x = y;    
        y = y->parent;    
    }    
    return y;    
}    
//递归地查询二叉查找树     
node *RB_Search(node *x, int k)    
{    
    //找到叶子结点了还没找到，或当前结点是所查找的结点     
    if(x->key == -1 || k == x->key)    
        return x;    
    //所查找的结点位于当前结点的左子树     
    if(k < x->key)    
        return RB_Search(x->left, k);    
    //所查找的结点位于当前结点的左子树     
    else    
        return RB_Search(x->right, k);    
}   
//红黑树的删除  
node *RB_Delete(Red_Black_Tree *T, node *z)  
{  
    //找到结点的位置并删除，这一部分与二叉查找树的删除相同  
    node *x, *y;  
    if(z->left == T->nil || z->right == T->nil)  
        y = z;  
    else y = Tree_Successor(T, z);  
    if(y->left != T->nil)  
        x = y->left;  
    else x = y->right;  
    x->parent = y->parent;  
    if(y->parent == T->nil)  
        T->root = x;  
    else if(y == y->parent->left)  
        y->parent->left = x;  
    else  
        y->parent->right = x;  
    Maintaining(y->parent);  
    if(y != z)  
    {  
        z->key = y->key;  
        z->p = y->p;  
        Maintaining(z);  
    }  
    //如果被删除的结点是黑色的，则需要调整  
    if(y->color == BLACK)  
        RB_Delete_Fixup(T, x);  
    return y;  
}  
//求最大覆盖点  
int Find_Pom(Red_Black_Tree *T)  
{  
    return T->root->o;  
}  
int main()  
{  
    //生成一棵树  
    Red_Black_Tree *T = new Red_Black_Tree;  
    char ch;  
    int start, end;  
    node *ret;  
    while(1)  
    {  
        cin>>ch;  
        switch (ch)  
        {  
            //插入一个区间  
        case 'I':  
            {  
            start = rand() % 100;  
            end = rand() % 100;
            cin >> start >> end;
            if(start > end)  
                swap(start, end);  
            cout<<start<<' '<<end<<endl;  
            //若端点已存在，不需要再加入，只需要对p做+1或-1操作  
            ret = RB_Search(T->root, start);  
            if(ret != T->nil)  
                ret->p++;  
            //若端点不存在，则加入  
            else  
            {  
                ret = new node(T->nil, start);  
                ret->p = 1;  
                RB_Insert(T, ret);  
            }  
            //对右端点操作相似  
            ret = RB_Search(T->root, end);  
            if(ret != T->nil)  
                ret->p--;  
            else  
            {  
                ret = new node(T->nil, end);  
                ret->p = -1;  
                RB_Insert(T, ret);  
            }  
            //输出结果  
            cout<<Find_Pom(T)<<endl;  
            break;  
            }  
            //删除一个区间，即做与插入相反的操作  
        case 'D':  
            cin>>start>>end;  
            ret = RB_Search(T->root, start);  
            if(ret != T->nil)  
            {  
                //左端对应的结点p-1  
                ret->p--;  
                if(ret->p == 0)  
                    RB_Delete(T, ret);  
            }  
            ret = RB_Search(T->root, end);  
            if(ret != T->nil)  
            {  
                //右端对应的结点p+1  
                ret->p++;  
                if(ret->p == 0)  
                    RB_Delete(T, ret);  
            }  
            //输出结果  
            cout<<Find_Pom(T)<<endl;  
            break;  
        }  
    }  
    return 0;  
}