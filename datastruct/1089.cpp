#include <iostream>
#include <string>
#include <map>
using namespace std;
const int MAXN = 101;
const int INF = 1e9;

int N, M;
map<string, int> mp;
int cost[MAXN][MAXN];
int A[MAXN][MAXN];

void init()
{
    for (int i = 0; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            A[i][j] = INF;
            if (i == j)
                A[i][j] = 0;
        }
}

void floyd()
{
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                if (A[i][k] + A[k][j] < A[i][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
}

int main()
{
    cin >> N >> M;
    int ni = 1;
    init();
    for (int i = 0; i < M; i++)
    {
        string a, b;
        int v;
        cin >> a >> b >> v;
        if (mp.find(a) == mp.end())
        {
            mp[a] = ni++;
        }
        if (mp.find(b) == mp.end())
        {
            mp[b] = ni++;
        }
        A[mp[a]][mp[b]] = v;
        A[mp[b]][mp[a]] = v;
    }

    floyd();

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string a, b;
        cin >> a >> b;
        if (mp.find(a) == mp.end() || mp.find(b) == mp.end() || A[mp[a]][mp[b]] == INF)
            cout << -1 << endl;
        else
            cout << A[mp[a]][mp[b]] << endl;
    }
}