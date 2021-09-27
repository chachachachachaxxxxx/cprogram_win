#include <iostream>
#include <string>
using namespace std;
const int MAXN = 1e5 + 1;

class my_queue{
private:
    int a[MAXN];
    int rear;
    int front;

public:
    my_queue(){
        rear = 0;
        front = 0;
    }
    ~my_queue(){
        
    };

    int enqueue(int tar)
    {
        if (rear - front >= MAXN)
            return -2;
        a[rear++ % MAXN] = tar;
        return 0;
    }

    int dequeue()
    {
        if (rear == front)
            return -1;
        return a[front++ % MAXN];
    }
};

int main()
{
    int N;
    cin >> N;
    my_queue mq;
    for (int i = 0; i < N; i++)
    {
        string op;
        cin >> op;
        if (op == "dequeue")
        {
            cout << mq.dequeue() << endl;
        } else if (op == "enqueue"){
            int opt;
            cin >> opt;
            if (mq.enqueue(opt) == -2)
            {
                cout << "Full" << endl;
            }
        }
    }
    return 0;
}