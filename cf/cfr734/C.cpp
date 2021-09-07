#include <iostream>
#include <string>
using namespace std;

const int MAXN = 2e5 + 10;
string str[MAXN];
int n;
int dp[MAXN];

void solve() {
    dp[0] = 0;
    
}

int main() {
    int T;
    scanf("%d\n", &T);
    while (T--) {
        scanf("%d\n", &n);
        for (int i = 0; i < n; i++) {
            cin >> str[i];
        }
        solve();
    }
}