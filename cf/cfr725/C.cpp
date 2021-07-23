#include <iostream>

#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 10;
int n, l, r;
int a[MAXN];

int binary(int *a, int m, int l, int r) {
    if (m > a[r])
        return r + 1;
    if (m < a[l])
        return l - 1;
    int k = (l + r) / 2;
    if (m == a[k])
        return k;
    else if (m < a[k])
        return binary(a, m, l, k - 1);
    else if (m > a[k])
        return binary(a, m, k + 1, r);
}

void solve() {
    sort(a, a + n);

    int lm = 0, rm = 0;
    long long ans = 0;
    int i1 = 0, i2 = 0;

    for (int i = 0; i < n - 1; i++) {
        lm = l - a[i];
        rm = r - a[i];
        i1 = lower_bound(a + i + 1, a + n, lm) - a;
        //cout << i1 << endl;
        if (i1 >= n)
            continue;
        else {
            i2 = upper_bound(a + i + 1, a + n, rm) - a;
            if (i2 == i + 1)
                continue;
            ans += i2 - i1;
        }
        //cout << "i1:" << i1 << " i2:" << i2 << endl;
    }
    cout << ans << endl;
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> l >> r;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve();
    }
}