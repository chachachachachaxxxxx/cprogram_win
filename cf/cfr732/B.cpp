#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 10;
int m, n;
char a[MAXN];
char c[MAXN];

void solve() {
    for (int i = 0; i < m; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        cin >> a;
        for (int j = 0; j < m; j++) {
            c[j] ^= a[j];
        }
    }
    for (int i = 0; i < m; i++) {
        cout << c[i];
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        solve();
    }
}