#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 2e5 + 10;
int c[MAXN], ran[MAXN], N;

typedef struct person{
    int jq;
    int key;
} PER;

PER ps[MAXN];

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
    int s = 0;
    while (x > 0)
    {
        s += c[x];
        x -= x & (-x);
    }
    return s;
}

int find(int x)
{
    int l = 1, r = N;
    int p = 0, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (mid - getsum(mid) >= x)
        {
            p = mid;
            r = mid - 1;
        } 
        else
        {
            l = mid + 1;
        }
    }
    return p;
}

int main()
{
    while (scanf("%d", &N) != EOF)
    {
        memset(c, 0, sizeof(c));

        for (int i = 0; i < N; i++)
            scanf("%d%d", ps[i].jq, ps[i].key);

        int pos;
        for (int i = N - 1; i >= 0; i--)
        {
            pos = find(ps[i].jq + 1);
            ran[pos - 1] = ps[i].key;
            add(pos, 1);
        }

        for (int i = 0; i < N; i++)
            cout << ran[i] << " ";
        cout << endl;
    }
}