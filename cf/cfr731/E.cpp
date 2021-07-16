#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 300010;
const int INF = 1003000000;
int l, n;
int airNo[MAXN];
int t[MAXN];
int rt[MAXN];
int lt[MAXN];

void solve () {
    for (int i = 0; i < l; i++)
        t[i] = INF;

    for (int i = 0; i < n; i++) {
        cin >> t[airNo[i] - 1];
    }

    rt[0] = t[0];
    for (int i = 0; i < l - 1; i++) {
        rt[i + 1] = min(rt[i] + 1, t[i + 1]);
    }

    lt[l-1] = t[l-1];
    for (int i = l - 1; i > 0; i--) {
        lt[i - 1] = min(lt[i] + 1, t[i - 1]);
    }

    for (int i = 0; i < l; i++)
    {
        cout << min(lt[i], rt[i]) << " ";
    }
    cout << endl;
}

int main () {
    int cnum;
    cin >> cnum;
    while (cnum--) {
        cin >> l >> n;
        for (int i = 0; i < n; i++)
            cin >> airNo[i];
        //for (int i = 0; i < n; i++)
        //    cout << airNo[i];
        //cout << endl;
        solve();
    }
}