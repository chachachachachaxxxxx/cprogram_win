#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1e3+10;
int c[MAXN][MAXN];
int N;

void update(int x, int y, int val)
{
    for (int i = x; i <= N; i += i & (-i))
        for (int j = y; j <= N; j += j & (-j))
            c[i][j] += val;
}

int getsum(int x, int y)
{
    int s = 0;
    for (int i = x; i > 0; i -= i & (-i))
        for (int j = y; j > 0; j -= j & (-j))
            s += c[i][j];
    return s;
}

int main()
{
    int T;
    scanf("%d", &T);
    int opt;
    char op[10];
    int x1, y1, x2, y2,ans;
    while (T--)
    {
        scanf("%d %d", &N, &opt);
        memset(c, 0, sizeof(c));

        for (int i = 0; i < opt; i++)
        {
            scanf("%s", op);
            if (op[0] == 'C')
            {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                update(x1, y1, 1);
                update(x1, y2 + 1, 1);
                update(x2 + 1, y1, 1);
                update(x2 + 1, y2 + 1, 1);
            }
            else if (op[0] == 'Q')
            {
                scanf("%d %d", &x1, &y1);
                ans = getsum(x1, y1);
                printf("%d\n", ans % 2);
            }
            // for (int j = 1; j <= N; j++)
            // {
            //     for (int k = 1; k <= N; k++)
            //     {
            //         ans = getsum(j, k);
            //         cout << (ans & 1) << " ";
            //     }
            //     cout << endl;
            // }
        }
        if (T)
            printf("\n");
    }
}