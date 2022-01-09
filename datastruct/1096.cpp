#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1e3 + 10;

struct point{
    int x, y;
};

struct edge{
    int x, y;
    double dis;
};

int N, M;
double ans;
point ps[MAXN];
edge e[MAXN * MAXN / 2];
int dsu[MAXN];

double dis(point a, point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool cmp(edge a, edge b)
{
    return a.dis < b.dis;
}

int root(int x)
{
    if (x != dsu[x]) 
        return dsu[x] = root(dsu[x]);
    else 
        return x;
}

void unionn(int x, int y)
{
    dsu[root(x)] = dsu[root(y)];
}

int main()
{
    cin >> N >> M;
    int ie = 0;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        ps[i].x = x;
        ps[i].y = y;
        for (int j = 0; j < i; j++)
        {
            e[ie].x = i;
            e[ie].y = j;
            e[ie].dis = dis(ps[i], ps[j]);
            ie++;
        }
        dsu[i] = i;
    }
    sort(e, e + ie, cmp);

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        unionn(x-1, y-1);
    }

    for (int i = 0; i < ie; i++)
    {
        // cout << e[i].x << " " << e[i].y << endl;
        if (M == N - 1)
            break;
        if (root(e[i].x) != root(e[i].y))
        {
            // cout << e[i].x << " " << e[i].y << endl;
            unionn(e[i].x, e[i].y);
            ans += e[i].dis;
            M++;
        }
    }
    printf("%.2lf\n", ans);
}