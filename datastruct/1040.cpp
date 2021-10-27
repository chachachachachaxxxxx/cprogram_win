#include <iostream>
#include <string>
using namespace std;
const int MAXN = 210;

int dp[MAXN];

int main()
{
    int N;
    cin >> N;
    string st;
    dp[0] = 1;
    for (int i = 0; i < N; i++)
    {
        cin >> st;
        for (int j = 1; j < (int)st.size(); j++)
        {
            int flag = 0;
            if (j - 1 - dp[j - 1] >= 0 && st[j] == st[j - 1 - dp[j - 1]])
            {
                int l = j - 1 - dp[j - 1], r = j;
                while (l < r)
                {
                    if (st[l] != st[r])
                        break;
                    l++;
                    r--;
                }
                if (l < r)
                    dp[j] = dp[j - 1];
                else
                {
                    dp[j] = dp[j - 1] + 2;
                    flag = 1;
                }
            }
            if (flag == 0)
            {
            if (j - dp[j - 1] >= 0 && st[j] == st[j - dp[j-1]])
            {
                int l = j  - dp[j - 1], r = j;
                while (l < r)
                {
                    if (st[l] != st[r])
                        break;
                    l++;
                    r--;
                }
                if (l < r)
                    dp[j] = dp[j - 1];
                else
                    dp[j] = dp[j - 1] + 1;
            }
            else
                dp[j] = dp[j - 1];
            }
        }
        cout << "case #" << i << ":" << endl;
        // cout << dp[2] << endl;
        for (int k = 0; k < (int)st.size(); k++)
            cout << dp[k] << endl;
    }
}