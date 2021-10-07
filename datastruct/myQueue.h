#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <iostream>
using namespace std;

class myQueue{
private:
    int *a;
    int rear;
    int front;
    int MAXN;

public:
    myQueue(int);
    ~myQueue();

    void clear();
    // 入队出队
    int enqueue(int);
    int dequeue();
    int find(int);
    // 判空判满
    int size();
    int is_Full();
    int is_Empty();
    // 读取队首或队尾元素
    int front_elem();
    int rear_elem();

    void print();
};

myQueue::myQueue(int N)
{
    MAXN = N;
    a = new int[MAXN];
    front = rear = 0;
}

myQueue::~myQueue()
{
    delete[] a;
}

void myQueue::clear()
{
    front = rear = 0;
}

int myQueue::enqueue(int tar)
{
    if (this->is_Full())
        return -1;
    a[rear++ % MAXN] = tar;
    return 1;
}

int myQueue::dequeue()
{
    if (this->is_Empty())
        return -2;      // 出队元素有可能是-2
    if (front >= MAXN)
    {
        front -= MAXN;
        rear -= MAXN;
    }
    return a[front++ % MAXN];
}

int myQueue::find(int tar)
{
    for (int i = 0; i < rear - front; i++)
    {
        if (a[(front + i) % MAXN] == tar)
            return i;
    }
    return -1;
}

int myQueue::size()
{
    return rear - front;
}

int myQueue::is_Empty()
{
    if (rear == front)
        return 1;
    return 0;
}

int myQueue::is_Full()
{
    if (rear - front >= MAXN)
        return 1;
    return 0;
}

int myQueue::front_elem()
{
    return a[front % MAXN];
}

void myQueue::print()
{
    for (int i = 0; i < this->size(); i++)
    {
        cout << a[(i + front) % MAXN] << " ";
    }
    cout << endl;
}

#endif