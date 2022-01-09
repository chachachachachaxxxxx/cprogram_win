#include <iostream>
#include <iomanip>
using namespace std;
const int MAXN = 1e3;
const int INF = 1e8;

int s[MAXN];
int dis[MAXN];
int pre[MAXN];
int G[MAXN][MAXN];

void out(int N)
{
    cout << setw(8) << "s" << setw(4) << "dis" << setw(4) << "pre" << endl;
    for (int i = 1; i <= N; i++)
    {
        cout << setw(4) << i;
        cout << setw(4) << s[i];
        if (dis[i] == INF)
        {
            cout << setw(4) << "INF";
        }
        else
            cout << setw(4) << dis[i];
        cout << setw(4) << pre[i] << endl;
    }
}

void init(int N)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            G[i][j] = INF;
            if (i == j)
                G[i][j] = 0;
        }
        dis[i] = INF;
        s[i] = 0;
        pre[i] = 0;
    }
}

void diji(int st, int N)
{
    dis[st] = 0;
    
    while (true)
    {
        int v = -1;
        for (int u = 1; u <= N; u++)
        {
            if (!s[u] && (v == -1 || dis[u] < dis[v]))
            {
                v = u;
            }
        }

        if (v == -1)
            break;

        s[v] = 1;
        // cout << v << endl;
        // cout << G[4][5];
        for (int u = 1; u <= N; u++)
        {
            // cout << G[v][u] << endl;
            if (dis[v] + G[v][u] < dis[u])
            {
                pre[u] = v;
                dis[u] = dis[v] + G[v][u];
                // cout << dis[v] << endl;
            }
            // dis[u] = min(dis[u], dis[v] + G[v][u]);
        }

        out(N);

        cout << endl;
    }
}

int N, M;
int main()
{
    cin >> N >> M;
    init(N);
    for (int i = 0; i < M; i++)
    {
        int a, b, v;
        cin >> a >> b >> v;
        G[a][b] = v;
        // cout << G[a][b] << endl;
    }
    
    diji(4, N);
    out(N);
}