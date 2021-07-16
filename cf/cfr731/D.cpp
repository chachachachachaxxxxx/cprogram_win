#include <iostream>
using namespace std;

const int MAXN = 200100;

int a[MAXN];
int b[MAXN];
int c[MAXN];
int l;

void solve() {
    c[0] = a[0];
    for (int i = 1; i < l; i++)
        c[i] = c[i - 1] | a[i];
    b[0] = 0;
    for (int i = 1; i < l; i++)
        b[i] = c[i] ^ a[i];

    for (int i = 0; i < l; i++)
        cout << b[i] << " ";
    cout << endl;
}

int main () {
    int cnum;
    cin >> cnum;
    while (cnum--) {
        cin >> l;
        for (int i = 0; i < l; i++)
            cin >> a[i];
        solve();
    }
}