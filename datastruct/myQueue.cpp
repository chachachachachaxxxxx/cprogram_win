#include "myQueue.h"

myQueue::myQueue(int N)
{
    a = new int[N + 1];
    front = rear = 0;
}

myQueue::~myQueue()
{
    delete[] a;
}

int myQueue::is_Empty()
{
    if (rear == front)
        return 1;

}