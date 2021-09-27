#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 10;

int a[MAXN];

int binary_search(int *a, int tar, int N)
{
    int l = 0, r = N - 1;
    int m = (l + r) / 2;
    while (l <= r)
    {
        if (a[m] == tar)
            return m;
        else if (a[m] < tar)
        {
            l = m + 1;
            m = (l + r) / 2;
        }
        else
        {
            r = m - 1;
            m = (l + r) / 2;
        }
    }
    return -1;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    sort(a, a + N);
    int tar;
    cin >> tar;
    cout << binary_search(a, tar, N);
    return 0;
}