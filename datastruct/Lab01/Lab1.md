<div align='center'><font size='70'><b>第一次书面作业</b></font></div>

## Q1

### Description

![](Q1.png)

### Solution

附在代码注释中

### code

#### reverse_LinkList

````c++
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
    while (p->next != NULL)   // 用数组记录链表的指针值
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

````

## Q2

### Description

![](Q2.png)

### Solution

附在代码注释中

### Code

#### insert

```c++
// 不带表头结点
// 在函数内部申请空间创建新结点
NODE *insert(NODE *head, int a, int key)
{
    NODE *A = new NODE;     // 创建新结点A
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

// 不带表头结点
// 在函数外部申请空间创建新节点
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
```

## Q3

### Description

![](Q3.png)

### Solution

附在代码注释中

### Code

#### mergeLinkList

```c++
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

```

