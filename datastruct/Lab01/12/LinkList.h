#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct node{
    int data;
    struct node *next;
} NODE;


// 不带表头结点
NODE* reverse_LinkList(NODE *head)
{
    if (head == NULL)   // 链表为空直接返回 
        return head; 
    NODE *p = head;
    int length = 0;     // 计算链表的长度
    while (p != NULL)   
    {
        p = p->next;
        length++;
    }

    if (length == 1)
        return head;
    
    NODE **a;           // 根据链表长度申请空间来开数组
    a = new NODE*[length];
    int i = 0;
    a[i++] = head;
    p = head;
    while (p->next != NULL)   // 用数组记录结点的指针值
    {
        a[i++] = p->next;
        p = p->next;
    }
    NODE *head2 = a[i - 1];     // 利用数组反转整个链表
    i--;
    p = head2;
    while (i - 1 >= 0)
    {
        p->next = a[i - 1];
        p = p->next;
        i--;
    }
    p->next = NULL;     
    delete[] a;         // 销毁申请空间
    return head2;
}

// 不带表头结点
// 在函数内部申请空间创建新节点
NODE *insert(NODE *head, int a, int key)
{
    NODE *A = new NODE;     // 创建新节点A
    A->data = a;
    A->next = NULL;
    if (head == NULL)       // 如果链表为空，则直接将头指针设为A，返回头指针即可
    {
        head = A;
        return head;
    }

    NODE *p = head;
    if (p->data == key)     // 如果链表第一个结点值即为key值，
    {                       // 则将结点A的指针值设为头指针，再将头指针设为结点A
        A->next = p;
        head = A;
        return head;
    }

    NODE *t = NULL;         // t结点为p结点的父结点
    while (p != NULL && p->data != key)
    {                       // 查找结点值为key的结点，并将其父结点设为t
        t = p;              // 结点值为key的结点可能存在也可能不存在
        p = p->next;        // 无论存在与否，结点t必然存在
    }
    t->next = A;            // 插入结点A
    A->next = p;            
    return head;
}

NODE* insert(NODE *head, NODE *a, int key)
{
    if (head == NULL)
    {
        head = a;
        return head;
    }
    NODE *p = head;
    
    if (head->data == key)
    {
        a->next = p;
        head = a;
        return head;
    }

    NODE *t = NULL;
    while (p != NULL && p->data != key)
    {
        t = p;
        p = p->next;
    }
    t->next = a;
    a->next = p;
    return head;
}

#endif