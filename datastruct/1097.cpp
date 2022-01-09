#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1e3 + 10;

// struct point{
//     int x, y;
// };

struct edge{
    int x, y;
    int dis;
};

int N, M;
int ans;
// point ps[MAXN];
edge e[MAXN * 15];
int dsu[MAXN];

// double dis(point a, point b)
// {
//     return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
// }

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
    for (int i = 0; i < M; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        // ps[i].x = x;
        // ps[i].y = y;
        // for (int j = 0; j < i; j++)
        // {
        //     e[ie].x = i;
        //     e[ie].y = j;
        //     e[ie].dis = dis(ps[i], ps[j]);
        //     ie++;
        // }
        e[i].x = x;
        e[i].y = y;
        e[i].dis = v;
    }
    for (int i = 1; i <= N; i++)
        dsu[i] = i;

    sort(e, e + M, cmp);

    // for (int i = 0; i < M; i++)
    // {
    //     int x, y;
    //     cin >> x >> y;
    //     unionn(x-1, y-1);
    // }

    for (int i = 0; i < M; i++)
    {
        // cout << e[i].x << " " << e[i].y << endl;
        if (ie == N - 1)
            break;
        if (root(e[i].x) != root(e[i].y))
        {
            // cout << e[i].x << " " << e[i].y << endl;
            unionn(e[i].x, e[i].y);
            ans += e[i].dis;
            ie++;
        }
    }
    cout << ans << endl;
    // printf("%.2lf\n", ans);
}