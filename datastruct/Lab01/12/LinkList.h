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

NODE *insert(int a, NODE *head, int key)
{
    NODE *p = head;
    NODE *t = NULL;
    while (p != NULL && p->key != key)
    {
        t = p;
        p = p->next;
    }
    if (p == NULL && t == NULL)
    {
        
    }
}

#endif