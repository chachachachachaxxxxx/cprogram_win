#include<iostream>
#include "myQueue.h"
#include "myQueue.cpp"
using namespace std;

const int MAXM = 5010;
const int MAXN = 1e6 + 10;

int cnt[MAXM];
int a[MAXN];
int Full(int *a, int length)
{
    for (int i = 1; i <= length; i++)
        if (a[i] == 0)
            return 0;
    return 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    //myQueue mq(n);
    int l, r;
    int lm, rm;
    l = r = 0;
    lm = 0;
    rm = n;
    int flag = 0;
    int flagF = 0;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        // mq.enqueue(k);
        cnt[k]++;
        // r++;
        a[r++] = k;
        flag = 0;
        if (flagF || Full(cnt, m))
        {
            while (1)
            {
                k = a[l];
                // k = mq.front_elem();
                // cout << k << endl;
                if (cnt[k] == 1)
                {
                    break;
                }
                // mq.dequeue();
                cnt[k]--;
                l++;
            }
            flagF = 1;
            flag = 1;
        }
        if (flag == 1)
        {
            if (r - l < rm - lm)
            {
                rm = r;
                lm = l;
            }
        }
        // mq.print();
        // cout << l << " " << r << endl;
    }
    cout << lm + 1 << " " << rm << endl;
    return 0;
}