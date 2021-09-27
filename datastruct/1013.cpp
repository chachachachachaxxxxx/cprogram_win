#include <iostream>
#include "my_queue.cpp"
#include <string>
using namespace std;

int main()
{
    int N, op;
    cin >> N >> op;
    int cas = 0;
    while (!(N == 0 && op == 0))
    {
        cout << "Case " << cas + 1 << ":"<< endl;
        string opra;
        int l = N > op ? op : N;
        my_queue mq(l * 2);
        for (int i = 0; i < l; i++)
        {
            mq.enqueue(i + 1);
        }

        int k;
        for (int i = 0; i < op; i++)
        {
            cin >> opra;
            if (opra == "N")
            {
                k = mq.dequeue();
                if (k <= l)
                    mq.enqueue(k);
                cout << k << endl;

            } else if (opra == "E") {
                cin >> k;
                if (k > l)
                {
                    mq.enqueue(k);
                }
                mq.To_head(k);
            }
        }
        cas++;
        cin >> N >> op;
    }
    return 0;
}