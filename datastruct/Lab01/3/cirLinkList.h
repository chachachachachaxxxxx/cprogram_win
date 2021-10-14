#ifndef CIRLINKLIST_H
#define CIRLINKLIST_H

typedef struct node{
    int data;
    struct node *next;
} NODE;

NODE *mergeLinkList(NODE *a, NODE *b)
{   
    if (a->next == NULL)
        return b;
    else if (b->next == NULL)
        return a;

    NODE *p, *q;
    p = a->next;
    q = b->next;


    NODE *m;
    m = a;
    while (p->next != a->next && q->next != b->next)
    {
        if (p->data <= q->data)
        {
            m->next = p;
            m = p;
            p = p->next;
        }
        else if (p->data > q->data)
        {
            m->next = q;
            m = q;
            q = q->next;
        }
    }

    int flag = 0;
    if (p->next == a->next)
    {
        while (q->next != b->next)
        {
            if (p->data <= q->data)
            {
                m->next = p;
                m = p;
                m->next = q;
                flag = 1;
            }
            m->next = q;
            m = q;
            q = q->next;
        }
        // if (flag == 0)
        // {
        //     if (p->data <= q->data)
        //     {
        //         m->next = p;
        //         m = p;
        //         m->next = q;
        //         m = q;
        //     } else {
        //         m->next = q;
        //         m = q;
        //         m->next = p;
        //         m = p;
        //     }
        // }
        // m->next = a->next;
        // return a;
    }

    
    if (q->next == b->next)
    {
        while (p->next != a->next)
        {
            if (q->data < p->data)
            {
                m->next = q;
                m = q;
                m->next = p;
                flag = 1;
            }
            m->next = p;
            m = p;
            p = p->next;
        }

        // if (flag == 0)
        // {
        //     if (p->data <= q->data)
        //     {
        //         m->next = p;
        //         m = p;
        //         m->next = q;
        //         m = q;
        //     } else {
        //         m->next = q;
        //         m = q;
        //         m->next = p;
        //         m = p;
        //     }
        // }
        // m->next = a->next;
        // return a;
    }

    if (flag == 0)
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
    m->next = a->next;
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