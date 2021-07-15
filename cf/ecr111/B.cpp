#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define MAXL 110
using namespace std;

int casenum;
string str;
int l, a, b;
int ans;
//int dp[MAXL][MAXL];

/*int mindeletesteps(int m, int n, int dp[][MAXL], string str) {
    if (m > n)
        return 0;
    if (m == n)
        return 1;
    if (dp[m][n] != -1)
        return dp[m][n];

    int res = 1 + mindeletesteps(m + 1, n, dp, str);

    for (int i = m + 1; i <= n; i++) {
        if (str[m] == str[i]) {
            res = min(res, mindeletesteps(m + 1, i - 1, dp, str) + mindeletesteps(i, n, dp, str));
        }
    }

    return dp[m][n] = res;
}*/

void solve() {
    int cnt = 1;
    for (int i = 1; i < l; i++) {
        if (str[i] != str[i - 1]) {
            cnt++;
        }
    }
    
    ans = a * l + max(l * b, (cnt / 2 + 1) * b);
    printf("%d\n", ans);
}

int main() {
    scanf("%d\n", &casenum);
    for (int i = 0; i < casenum; i++) {
        scanf("%d %d %d\n", &l, &a, &b);
        cin >> str;
        getchar();
        solve();
    }
    return 0;
}