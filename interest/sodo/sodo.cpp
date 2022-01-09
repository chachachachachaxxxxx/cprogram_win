#include <iostream>
using namespace std;
const int MAXN = 10;

void out();

int G[MAXN][MAXN];
int ans[MAXN][MAXN];

bool judge(int i, int j)
{
    for (int k = 0; k < 9; k++)
    {
        if ((G[i][k] == G[i][j] && k != j )||( G[k][j] == G[i][j] && k != i))
            return false;
    }

    int x, y;
    x = i / 3 * 3 + 1;
    y = j / 3 * 3 + 1;
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (G[i][j] == G[x+dx][y+dy] && (x + dx != i || y + dy != j))
                return false;
        }
    }
    return true;
}

bool dfs(int i, int j)
{
    if (j == 9)
    {
        i++;
        j = 0;
    }
    if (i == 9)
    {
        for (int x = 0; x < 9; x++)
        {
            for (int y = 0; y < 9; y++)
                ans[x][y] = G[x][y];
        }
        return true;
    }

    if (G[i][j] != 0)
        return dfs(i, j + 1);

    // cout << endl;
    // out();
    // cout << endl;
    for (int k = 1; k <= 9; k++)
    {
        G[i][j] = k;
        
        if (judge(i, j))
        {
            /*cout << endl;
            out();
            cout << endl;*/
            if (dfs(i, j+1))
                return true;
        }
        G[i][j] = 0;
    }

    return false;
}

void out()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    int N;
    while (cin >> N)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> G[i][j];
            }
        }
        dfs(0, 0);
        cout << endl;
        out();         
    }
}