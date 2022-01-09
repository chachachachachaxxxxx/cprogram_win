#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e3 + 10;

struct edge{
    int value;
    int start;
    int end;
};

int ebsu[3 * MAXN];
edge e[3 * MAXN];
int vertex[MAXN];
int N, M;

bool cmp(edge a, edge b)
{
    return a.value < b.value;
}

int root(int x, int *ebsu)
{
    if (ebsu[x] != x)
        return ebsu[x] = root(ebsu[x], ebsu);
    return x;
}

void unionn(int x, int y, int *ebsu)
{
    int yroot = root(y, ebsu);
    if (ebsu[x] != x)
    {
        unionn(ebsu[x], yroot, ebsu);
    }
    ebsu[x] = yroot;
    // while (x != ebsu[x])
    // {
    //     x = ebsu[x];
    //     ebsu[x] = yroot;
    // }
    // ebsu[root(x, ebsu)] = yroot;
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N;i++)
    {
        vertex[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, v;
        cin >> a >> b >> v;
        e[i].value = v;
        e[i].start = a;
        e[i].end = b;
        unionn(a, b, vertex);

        ebsu[i] = i;
    }

    for (int i = 2; i <= N; i++)
    {
        if (root(1, vertex) != root(i, vertex))
        {
            cout << -1 << endl;
            return 0;
        }
    }

    // if (M < N - 1)
    // {
    //     cout << -1 << endl;
    //     return 0;
    // }

    // for (int i = 1; i <= N; i++)
    // {
    //     if (vertex[i] == false)
    //     {
    //         cout << i << endl;
    //         cout << -1 << endl;
    //         return 0;
    //     }
    // }

    sort(e, e + M, cmp);
    for (int i = 0; i < M; i++)
    {
        
    }

        int k = 0;
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        // if (k == N - 1)
        //     break;
        if (root(e[i].start, ebsu) != root(e[i].end, ebsu))
        {
            // cout << e[i].start << " " << e[i].end << " " << e[i].value << endl;
            unionn(e[i].start, e[i].end, ebsu);
            ans += e[i].value;
            k++;
        }
    }
    cout << ans << endl;
}