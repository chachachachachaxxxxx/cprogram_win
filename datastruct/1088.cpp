#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 101;
const int INF = 1e9;

int N, M;
struct edge{
    int first;
    int second;
    int N;
};

vector<edge> ver[MAXN];
int pathone[MAXN];
int pre[MAXN];
int step[MAXN];
long stepNumber[MAXN];
bool s[MAXN];

void show()
{
    for (int i = 1; i <= N; i++)
    {
        if (step[i] == INF)
            cout << -1 << " ";
        else
            cout << step[i] << " ";
    }
    cout << endl;
}

void diji()
{
    stepNumber[1] = 1;
    step[1] = 0;
    priority_queue<pair<int, int>> que;
    que.push(make_pair(-step[1], 1));
    while (!que.empty())
    {
        int v = que.top().second;
        que.pop();
        if (s[v] == true)
            continue;
        s[v] = true;

        cout << v << endl;
        for (auto x: ver[v])
        {
            // if (step[x.first] == INF)
            // {
            if (step[v] + x.second < step[x.first])
            {
                step[x.first] = step[v] + x.second;
                // pathone[v] = x.first;
                pre[x.first] = v;
                stepNumber[x.first] = x.N * stepNumber[v];
                que.push(make_pair(-step[x.first], x.first));
                show();
            }
            else if (step[v] + x.second == step[x.first])
            {
                
                stepNumber[x.first] += stepNumber[v];
                cout << endl;
                cout << v << " " << x.first << endl;
                cout << step[v] + x.second << " " << stepNumber[x.first] << endl;
            }
            // }
        }
    }
}

void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        step[i] = INF;
    }
}

void out(int N)
{
    if (step[N] == INF)
        cout << -1 << endl
             << 0 << endl
             << -1 << endl;
    else
    {
        cout << step[N] << endl
             << stepNumber[N] << endl;
        int i = N;
        while (i != 1 )
        {
            pathone[pre[i]] = i;
            i = pre[i];
        }
        while (i != N )
        {
            cout << i << " ";
            i = pathone[i];
        }
        cout << N << endl;
    }
}

int main()
{
    cin >> N >> M;
    init();
    for (int i = 0; i < M; i++)
    {
        int a, b, v;
        cin >> a >> b >> v;
        bool flag = true;
        for (int j = 0; j < ver[a].size(); j++)
        {
            if (ver[a][j].first == b && ver[a][j].second == v)
            {
                ver[a][j].N++;
                flag = false;
                break;
            }
        }
        if (flag)
        {
            edge e;
            e.first = b;
            e.second = v;
            e.N = 1;
            ver[a].push_back(e);
        }

        flag = true;
        for (int j = 0; j < ver[b].size(); j++)
        {
            if (ver[b][j].first == a && ver[b][j].second == v)
            {
                ver[b][j].N++;
                flag = false;
                break;
            }
        }
        if (flag)
        {
            edge e;
            e.first = a;
            e.second = v;
            e.N = 1;
            ver[b].push_back(e);
        }
    }
    diji();
    out(N);
}