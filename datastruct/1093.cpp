#include <iostream>
using namespace std;
const int MAXN = 101;
const int INF = 1e8;

int N, M;
int G[MAXN][MAXN];
int A[MAXN][MAXN];

void init(int N)
{
    for (int i = 1; i <= N; i++)
    {
        G[i][0] = 0;
        for (int j = 1; j <= N; j++)
        {
            G[i][j] = INF;
            if (i == j)
                G[i][j] = 0;
        }
    }
}

void floyd(int N)
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (G[i][j] > G[i][k] + G[k][j])
                {
                    G[i][j] = G[i][k] + G[k][j];
                    // if (G[i][j] > G[i][0])
                    // {
                    //     G[i][0] = G[i][j];
                    // }
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    init(N);
    for (int i = 0; i < M; i++)
    {
        int a, b, v;
        cin >> a >> b >> v;
        if (v < G[a][b])
            G[a][b] = G[b][a] = v;
    }
    floyd(N);

    int ans = 0;
    int ansdis = INF;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (G[i][j] > G[i][0])
            {
                G[i][0] = G[i][j];
            }
        }
        if (G[i][0] == INF)
        {
            ans = 0;
            break;
        }
            if (G[i][0] < ansdis)
            {
                ans = i;
                ansdis = G[i][0];
            }
    }
    if (ans != 0)
        cout << ans << " " << ansdis << endl;
    else
        cout << ans << endl;
}