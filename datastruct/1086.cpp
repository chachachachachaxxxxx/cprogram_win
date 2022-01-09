#include <iostream>
using namespace std;
const int MAXN = 1e3 + 10;

int N, M;
int d[MAXN];
int dsu[MAXN];

int root(int x)
{
    if (x != dsu[x])
        return dsu[x] = root(dsu[x]);
    return x;
}

void unionn(int x, int y)
{
    int yroot = root(y);
    if (dsu[x] != x)
    {
        unionn(dsu[x], yroot);
    }
    dsu[x] = yroot;
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        dsu[i] = i;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        if (root(a) != root(b))
            unionn(a, b);
        d[a]++;
        d[b]++;
    }
        // cout << endl;

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i == dsu[i])
            cnt++;
        if (d[i]&1)
        {
            cout << "0" << endl;
            return 0;
        }
    }
    if (cnt > 1)
        {
            cout << "0" << endl;
            return 0;
        }
    cout << "1" << endl;
}