#include <iostream>

class my_queue{
private:
    int *a;
    int rear;
    int front;
    int length;

public:
    my_queue(int N){
        rear = 0;
        front = 0;
        a = new int[N];
        length = N;
    }
    ~my_queue(){
        delete[] a;
    };

    int enqueue(int tar)
    {
        if (rear - front >= length)
            return -2;
        a[rear++ % length] = tar;
        return 0;
    }

    int dequeue()
    {
        if (rear == front)
            return -1;
        if (front >= length)
        {
            front -= length;
            rear -= length;
        }
        return a[front++ % length];
    }

    int To_head(int tar)
    {
        int k = -1;
        for (int i = 0; i < (rear - front); i++)
        {
            if (a[(front + i) % length] == tar)
            {
                k = i;
            }
        }
        if (k == -1)
            return -1;
        for (int i = k; i > 0; i--)
        {
            a[(front + i) % length] = a[(front + i - 1) % length];
        }
        a[front % length] = tar;
        return 0;
    }
};