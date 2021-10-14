#include <iostream>
#include "LinkList.h"
using namespace std;

// void insert(int a, NODE *head, int key)
// {
//     NODE *A = new NODE;
//     A->data = a;
//     A->next = NULL;
//     NODE *p = head;
//     if (head == NULL)
//     {
//         head = A;
//         return;
//     }
//     NODE *t = NULL;
//     while (p != NULL && p->data != key)
//     {
//         t = p;
//         p = p->next;
//     }
//     t->next = A;
//     A->next = p;
// }

void print(NODE *head)
{
    // if (head == NULL)
    // {
    //     cout << endl;
    //     return;
    // }
    NODE *p = head;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void removeall(NODE *head)
{
    NODE *p = head;
    head = NULL;
    NODE *q;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        delete q;
    }
}

int main()
{
    int n, n1;
    NODE *h1 = NULL;
    NODE *h2 = new NODE;
    h2->data = 1;
    h2->next = NULL;
    n1 = 0;
    while (cin >> n)
    {   
        // NODE *A = new NODE;
        // A->data = n;
        // A->next = NULL;
        h1 = insert(h1, n, n1);
        // print(h1);
        n1 = n;
    }

    print(h1);
    h1 = reverse_LinkList(h1);
    print(h1);


    removeall(h1);
    removeall(h2);
    // print(h1);
    // print(h2);
}