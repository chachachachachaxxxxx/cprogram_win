#include <iostream>
using namespace std;
const int MAXN = 1e3+10;
const int INF = 0x7ffffff;

struct point{
    int x, y;
};

point ps[MAXN];
int N;
int mat[MAXN][MAXN];
int lowcost[MAXN];
int closeset[MAXN];
int ans;
bool flag;

int dis(int a, int b)
{
    // cout << abs(ps[a].x - ps[b].x) << endl;
    return abs(ps[a].x - ps[b].x) + abs(ps[a].y - ps[b].y);
}

void prim()
{
    int min;
    for (int i = 1; i <= N; i++)
    {
        lowcost[i] = dis(1, i);
        // cout << lowcost[i] << endl;
        // closest[i] = 1;
    }

    int k = 0;
    for (int i = 1; i <= N; i++)
    {
        min = INF;
        for (int j = 1; j <= N; j++)
        {
            if (lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            } else if (lowcost[j] == min)
            {
                flag = true;
            }
        }

        if (min == INF)
            break;
        ans += min;
        lowcost[k] = 0;
        for (int j = 1; j <= N; j++)
        {
            int d = dis(k, j);
            if (d != 0 && d < lowcost[j])
            {
                lowcost[j] = d;
                // closest[j] = k;
            }
        }
    }
}

int main()
{
    while(cin >> N)
    {
        for (int i = 1; i <= N; i++)
        {
            cin >> ps[i].x >> ps[i].y;
        }
        ans = 0;
        flag = false;
        prim();
        cout << ans << endl;
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}