#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 5e4 + 1e3;
char a[MAXN];
char b[MAXN];
int dp[2][MAXN + 1];

int main()
{
    cin >> a >> b;
    for (int i = 0; i < MAXN; i++)
        dp[0][i] = dp[1][i] = 0;
    int lena = strlen(a);
    int lenb = strlen(b);
    int max = 0;
    int i, j;
    for (i = 1; i <= lena; i++)
    {
        for (j = 1; j <= lenb; j++)
        {
            if (a[i-1] == b[j-1])
                dp[i & 1][j] = dp[(i - 1) & 1][j - 1] + 1;
            
            if (dp[i & 1][j] > max)
                max = dp[i & 1][j];
        }
    }
    cout << max << endl;
}