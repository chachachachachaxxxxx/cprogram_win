#include <iostream>
using namespace std;
const int MAXN = 1e4 + 10;
const int INF = 1e5;

int a[MAXN][MAXN];
// int cost[MAXN][MAXN];
double rate[MAXN];
int N, M;

void floyd(int N)
{
    int i, j, k;
    // for (i = 1; i <= N; i++)
    //     for (j = 1; j <= N; j++)
    // {
    //     a[i][j] = cost[i][j];
    // }
    for (k = 1; k <= N; k++)
        for (i = 1; i <= N; i++)
            for (j = 1; j <= N; j++)
            {
                if (a[i][k] + a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
}

void calrate(int N)
{
    for (int i = 1; i <= N; i++)
    {
        int s = 0;
        for (int j = 1; j <= N; j++)
        {
            if (a[i][j] <= 6)
                s++;
        }
        rate[i] = s * 100.0 / N;
    }
}

void init(int N)
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            a[i][j] = INF;
            if (i == j)
                a[i][j] = 0;
        }
}

int main()
{
    cin >> N >> M;
    init(N);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }

    floyd(N);
    calrate(N);
    for (int i = 1; i <= N; i++)
    {
        printf("%d: %.2lf%%\n", i, rate[i]);
    }
}