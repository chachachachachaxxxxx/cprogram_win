#include <iostream>
using namespace std;

const int MAXL = 200010;
int a[MAXL];
int l;

int gcd(int a, int b) {
    if (a > b)
        return gcd(b, a);
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int end(int *a) {
    for (int i = 0; i < l - 1; i++) {
        if (a[i] != a[i+1])
            return 1;
    }
    return 0;
}

void solve() {
    int cnt = 0;
    while (end(a)) {
        int temp = a[0];
        for (int i = 0; i < l - 1; i++)
            a[i] = gcd(a[i], a[i + 1]);
        a[l - 1] = gcd(temp, a[l - 1]);
        //for (int i = 0; i < l; i++)
        //    cout << a[i];
        cnt++;
    }

    cout << cnt << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> l;
        for (int i = 0; i < l; i++)
            cin >> a[i];
        solve();
    }
    return 0;
}