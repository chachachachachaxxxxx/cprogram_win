#include <iostream>
using namespace std;

const int MAXN = 2e5 + 10;
int pn;
int p[MAXN];

void solve() {
    int ans = -1;
    int sum = 0;
    for (int i = 0; i < pn; i++)
        sum += p[i];
    if (sum / pn * pn != sum) {
        cout << ans << endl;
        return;
    }
    int ave = sum / pn;
    ans++;
    for (int i = 0; i < pn; i++) {
        if (p[i] > ave)
            ans++;
    }
    cout << ans << endl;
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        cin >> pn;
        for (int i = 0; i < pn; i++)
            cin >> p[i];
        solve();
    }
}