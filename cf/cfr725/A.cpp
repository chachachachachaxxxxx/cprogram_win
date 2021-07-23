#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 110;
int ston;
int p[MAXN];

void solve() {
    int i1 = 0, i2 = 0;
    int minn, maxn;
    minn = 110;
    maxn = 0;
    for (int i = 0; i < ston; i++) {
        if (p[i] < minn) {
            minn = p[i];
            i1 = i;
        }
        if (p[i] > maxn) {
            maxn = p[i];
            i2 = i;
        }
    }

    int ans = 0;
    if (min(i1 + 1, ston - i1) <= min(i2 + 1, ston - i2)) {
        if (i1 + 1 < ston - i1) {
            ans = i1 + 1 + min(i2 - i1, ston - i2);
        } else {
            ans = ston - i1 + min(i2 + 1, i1 - i2);
        }
    } else {
        if (i2 + 1 < ston - i2) {
            ans = i2 + 1 + min(i1 - i2, ston - i1);
        } else {
            ans = ston - i2 + min(i1 + 1, i2 - i1);
        }
    }

    cout << ans << endl;
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        cin >> ston;
        for (int i = 0; i < ston; i++)
            cin >> p[i];
        solve();
    }
}