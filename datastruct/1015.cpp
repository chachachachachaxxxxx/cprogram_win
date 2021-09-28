#include<iostream>
#include "myQueue.h"
#include "myQueue.cpp"
using namespace std;

int main()
{
    int m, n, times;
    cin >> m >> n;
    myQueue mq(m);
    times = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        if (mq.find(m) == -1)
        {
            if (mq.is_Full())
                mq.dequeue();
            mq.enqueue(m);
            times++;
        }
    }
    cout << times;
    return 0;
}