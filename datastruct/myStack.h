#ifndef MYSTACK_H
#define MYSTACK_H

class myStack{
private:
    int *a;
    int len;
    int ptr;

public:
    myStack(int);
    ~myStack();
    bool empty();
    int size();

    void clear();
    void reverse();
    void pop();
    void push(int);

    int top();

    // 其他函数
    int find_max();
};

myStack::myStack(int N)
{
    a = new int[N];
    len = N;
    ptr = 0;
}

myStack::~myStack()
{
    delete[] a;
}

bool myStack::empty()
{
    if (ptr == 0)
        return true;
    return false;
}

int myStack::size()
{
    return ptr;
}

void myStack::clear()
{
    ptr = 0;
}

void myStack::pop()
{
    ptr--;
}

void myStack::push(int tar)
{
    a[ptr++] = tar;
}

int myStack::top()
{
    return a[ptr - 1];
}

int myStack::find_max()
{
    int k = a[0];
    for (int i = 1; i < ptr; i++)
    {
        if (a[i] > k)
            k = a[i];
    }
    return k;
}

void swap(int&a, int&b)
{
    int k = a;
    a = b;
    b = k;
}

void myStack::reverse()
{
    for (int i = 0; i < ptr / 2; i++)
    {
        swap(a[i], a[ptr - i - 1]);
    }
    return;
}

#endif