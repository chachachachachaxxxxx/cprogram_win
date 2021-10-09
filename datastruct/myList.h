#ifndef MYLIST_H
#define MYLIST_H
#include <cstdio>

struct node{
    int value;
    node* pre;
    node* next;
};
// typedef struct node NODE;

class myList{
private:
    node *head=NULL;

public:
    myList();
    ~myList();
    int add(int);
    int remove(int);
    int print();
};

myList::myList()
{

}

myList::~myList()
{
    node *q;
    node *p;
    p = head;
    if (head != NULL)
    {
        while (p->next != head)
        {
            q = p->next;
            delete p;
            p = q;
        }
        delete p;
    }
}

int myList::add(int value)
{
    node *first = new node;
    first->value = value;
    if (head == NULL)
    {
        first->pre = first;
        first->next = first;
        head = first;
        return 1;
    } else {
        node *p = head;
        while (p->next != head)
            p = p->next;
        p->next = first;
        first->pre = p;
        first->next = head;
        head->pre = first;
        return 2;
    }
    return 0;
}

int myList::remove(int value)
{
    node *p = head;
    node *q;
    int t = 0;
    if (head == NULL)
        return -1;
    while (p->next != head)
    {
        q = p->next;
        if (p->value == value)
        {
            p->next->pre = p->pre;
            p->pre->next = p->next;
            if (p == head)
                head = q;
            delete p;
            t++;
        }
        p = q;
    }
    if (p->value == value)
    {
        if (p->pre == p)
        {
            head = NULL;
        } else {
            p->next->pre = p->pre;
            p->pre->next = p->next;
        }
        delete p;
        t++;
    }
    if (t == 0)
        return -1;
    return 0;
}

int myList::print()
{
    if (head == NULL)
        return -1;
    node *p = head;
    while (p->next != head)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("%d\n", p->value);
    return 0;
}

#endif
