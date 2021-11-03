#include <iostream>
using namespace std;
const int MAXN = 1e5 + 10;
int c[MAXN], a[MAXN], b[MAXN], N;

void add(int x, int val)
{
    while (x <= N)
    {
        c[x] += val;
        x += x & (-x);
    }
}

int getsum(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += c[x];
        x -= x & (-x);
    }
    return sum;
}

int find(int x)
{
    int l = 1, r = N;
    int p = 0;
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (getsum(mid) >= x)
        {
            p = mid;
            r = mid - 1;
        }
        else 
            l = mid + 1;
    }
    return p;
}

int main()
{
    cin >> N;
    int k;
    a[0] = N;
    for (int i = 1; i < N; i++)
    {
        cin >> k;
        a[i] = k;
    }
    for (int i = 1; i <= N; i++)
    {
        add(i, 1);
    }

    int pos;
    for (int i = N - 1; i > 0; i--)
    {
        pos = find(a[i] + 1);
        b[i] = pos;
        add(pos, -1);
    }
    pos = find(1);
    b[0] = pos;

    for (int i = 0; i < N; i++)
        cout << b[i] << endl;
}