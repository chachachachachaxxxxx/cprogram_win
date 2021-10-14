#include <iostream>
#include "cirLinkList.h"
using namespace std;

void print(NODE *head)
{
    // if (head == NULL)
    // {
    //     cout << endl;
    //     return;
    // }
    NODE *p = head->next;
    if (head->next == NULL)
    {
        cout << endl;
        return;
    }
    while(p->next != head->next)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << p->data << endl;
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
    NODE *h1t = new NODE;
    NODE *h2t = new NODE;
    NODE *h1 = NULL;
    NODE *h2 = NULL;
    h1t->data = h2t->data = 0;
    h1t->next = h1;
    h2t->next = h2;
    
    cout << "input the num of list1:" << endl;
    int len1, len2;
    cin >> len1;
    cout << "input list1:" << endl;
    int n;
    int n1 = 0;
    for (int i = 0; i < len1; i++)
    {
        cin >> n;
        h1t = insert(h1t, n, n1);
        //print(h1t);
        n1 = n;
    }

    cout << "input the num of list2:" << endl;
    cin >> len2;
    cout << "input list2:" << endl;
    n1 = 0;
    for (int i = 0; i < len2; i++)
    {
        cin >> n;
        h2t = insert(h2t, n, n1);
        n1 = n;
    }

    print(h1t);
    print(h2t);
    

    h1t = mergeLinkList(h1t, h2t);
    print(h1t);

    // removeall(h1t);
    // removeall(h2t);
}