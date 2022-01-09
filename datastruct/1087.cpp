#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1010;

vector<int> vertex[MAXN];
int N, M, S;
bool verb[MAXN];
int path[MAXN * 3];
int p;

void dfs(int x)
{
    verb[x] = true;
    path[p++] = x;
    sort(vertex[x].begin(), vertex[x].end());
    // bool flag = false;
    for (int i = 0; i < vertex[x].size(); i++)
    {
        if (!verb[vertex[x][i]])
        {
            dfs(vertex[x][i]);
            path[p++] = x;
            // flag = true;
        }
    }
    // if (flag)
        // path[p++] = x;
}

int main()
{
    cin >> N >> M >> S;
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }

    dfs(S);
    for (int i = 1; i <= N; i++)
    {
        if (verb[i] == false)
        {
            path[p++] = 0;
            break;
        }
    }
    for (int i = 0; i < p; i++)
        cout << path[i] << " ";
    cout << endl;
}