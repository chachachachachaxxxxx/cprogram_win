#include <iostream>
using namespace std;
const int MAXN = 101;
int terms[MAXN];
int NO[MAXN][MAXN];

int f(int k, int N)
{
    int mink = 11;
    for (int i = 0; i < N; i++)
        if (terms[i] > k && terms[i] <= mink)
        {
            mink = terms[i];
        }
    if (mink != 11)
        return mink;
    return 0;
}

int main()
{
    int N;
    cin >> N;
    int sum = 0, maxm = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> terms[i];
        sum += terms[i];
        if (terms[i] > maxm)
            maxm = terms[i];
    }

    int mink, k, num, numk;
    k = 0;
    numk = 0;
    while((mink = f(k, N)) != 0)
    {
        num = 0;
        for (int i = 0; i < N; i++)
            if (terms[i] >= mink)
                num++;

        int start = 1;
        if (num == 1)
        {
            start = 2;
            num++;
        }
        for (int i = 0; i < N; i++)
        {
            if (terms[i] >= mink)
            {
                int number = start + numk;
                for (int j = k * 10; j < mink * 10; j++)
                {
                    NO[i][j] = number;
                    number += num;
                }
                start++;
            }
        }
        numk += num * (mink - k) * 10;
        k = mink;
        cout << mink << " " << num << " " << endl;
    }


    for (int i = 0; i < N; i++)
    {
        cout << "#" << i + 1 << endl;
        for (int j = 0; j < terms[i] * 10; j++)
        {
            if (j % 10 == 9)
                cout << NO[i][j] << endl;
            else
                cout << NO[i][j] << " ";
        }
    }
}