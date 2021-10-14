#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct node{
    int data;
    struct node *next;
} NODE;

NODE* reverse_LinkList(NODE *head)
{
    if (head == NULL)
        return head;
    NODE *p = head;
    int length = 0;
    while (p != NULL)
    {
        p = p->next;
        length++;
    }
    int *a;
    a = new int[length];
    int i = 0;
    p = head;
    while (p != NULL)
    {
        a[i++] = p->data;
        p = p->next;
    }
    p = head;
    i = length;
    while (p != NULL)
    {
        p->data = a[--i];
        p = p->next;
    }
    delete[] a;
    return head;
}

NODE *insert(NODE *head, int a, int key)
{
    NODE *A = new NODE;
    A->data = a;
    A->next = NULL;
    if (head == NULL)
    {
        head = A;
        return head;
    }
    NODE *p = head;
    
    if (p->data == key)
    {
        A->next = p;
        head = A;
        return head;
    }

    NODE *t = NULL;
    while (p != NULL && p->data != key)
    {
        t = p;
        p = p->next;
    }
    t->next = A;
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