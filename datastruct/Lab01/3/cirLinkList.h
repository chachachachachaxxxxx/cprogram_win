#ifndef CIRLINKLIST_H
#define CIRLINKLIST_H

typedef struct node{
    int data;
    struct node *next;
} NODE;

// 由于本题不能申请新的内存空间
// 故而新链表主要是改变原先两个链表中的结点的指针值形成的
NODE *mergeLinkList(NODE *a, NODE *b)
{   
    if (a->next == NULL)    // 如果某个链表为空，则直接返回另外一个链表
        return b;
    else if (b->next == NULL)
        return a;

    NODE *p, *q;        // p结点记录a链表遍历到的结点，q结点记录b链表遍历到的结点
    p = a->next;
    q = b->next;

    NODE *m;            // m结点记录新表遍历到的结点
    m = a;
    while (p->next != a->next && q->next != b->next) // 同时遍历a，b链表直到遍历到某个链表的结尾结点
    {
        if (p->data <= q->data) // 如果q结点值大于等于p结点值，则将p结点记录进新表
        {
            m->next = p;
            m = p;
            p = p->next;
        }
        else if (p->data > q->data) // 如果p结点值大于q节点值，则将q结点记录进新表
        {
            m->next = q;
            m = q;
            q = q->next;
        }
        //printf("%d\n", m->data);
    }

    // printf("%d\n", m->data);
    int flag = 0;   // 记录是否处理了最后一个结点
    if (p->next == a->next) // 如果是a链表先遍历到结尾结点
    {
        while (q->next != b->next) // 将b链表剩余的结点记录进新表
        {
            if (flag == 0 && p->data <= q->data) // 处理a链表的结尾结点，将其记录进新表
            {
                m->next = p;
                m = p;
                flag = 1;
            }
            //printf("%d\n", m->data);
            m->next = q;
            m = q;
            q = q->next;
        }
        if (flag == 1) // 如果处理了a链表的结尾结点，则处理b链表的结尾结点
        {
            m->next = q;
            m = q;
        }
    }
    else if (q->next == b->next) // 如果是b链表先遍历到结尾节点
    {
        while (p->next != a->next) // 将a链表剩余的结点记录进新表
        {
            if (flag == 0 && q->data < p->data) // 处理b链表的结尾结点，将其记录进新表
            {
                m->next = q;
                m = q;
                flag = 1;
            }
            m->next = p;
            m = p;
            p = p->next;
        } 
        if (flag == 1) // 如果处理了b链表的结尾结点，则可以处理a链表的结尾结点
        {
            m->next = q;
            m = q;
        }
    }

    if (flag == 0)  // 如果两个结尾结点均没记录进新表，处理最后的两个结点
    {
        if (p->data <= q->data)
        {
            m->next = p;
            m = p;
            m->next = q;
            m = q;
        } else {
            m->next = q;
            m = q;
            m->next = p;
            m = p;
        }
    }
    m->next = a->next; // 处理最后一个结点的指针值，使之成为环形链表
    return a;
}

NODE *insert(NODE *head, int a, int key)
{
    NODE *A = new NODE;
    A->data = a;
    A->next = head->next;
    
    if (head->next == NULL)
    {
        head->next = A;
        A->next = A;
        return head;
    }

    NODE *p = head->next;

    if (head->next->data == key)
    {
        A->next = head->next;
        while (p->next != head->next)
            p = p->next;
        head->next = A;
        p->next = head->next;
        return head;
    }

    
    while (p->next != head->next && p->next->data != key)
    {
        p = p->next;
    }
    if (p->next == head->next)
    {
        p->next = A;
        A->next = head->next;
        return head;
    }
    NODE *q = p->next;
    p->next = A;
    A->next = q;
    return head;
}

#endif