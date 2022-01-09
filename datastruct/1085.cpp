#include <iostream>
using namespace std;
const int MAXW = 81;
const int MAXH = 1e3 + 10;

char map[MAXH][MAXW];

int W, H;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int sum = 0;

void dfs(int x, int y)
{
    if (x < 0 || x >= H || y < 0 || y >= W)
        return ;
    
    if (map[x][y] == '.')
        return ;

    map[x][y] = '.';
    sum++;
    for (int i = 0; i < 4; i++)
    {
        dfs(x + dx[i], y + dy[i]);
    }
}

void solve()
{
    int ans = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (map[i][j] == '*')
            {
                dfs(i, j);
                if (sum > ans)
                    ans = sum;
                // cout << ans << endl;
                sum = 0;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    cin >> W >> H;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> map[i][j];
        }
        getchar();
    }

    solve();
}
