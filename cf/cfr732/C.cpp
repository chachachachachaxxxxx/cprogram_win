#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 10;
int a[MAXN];
int l;
int even[MAXN];
int odd[MAXN];

void solve() {
    for (int i = 0; i < MAXN; i++) {
        even[i] = odd[i] = 0;
    }
        int io, ie;
    io = ie = 0;
    for (int i = 0; i < l; i++) {
        if (i & 1) {
            odd[io++] = a[i];
        } else {
            even[ie++] = a[i];
        }
    }
    sort(even, even + ie);
    sort(odd, odd + io);
    /*for (int i = 0; i < ie; i++)
    {
        cout << even[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < io; i++)
    {
        cout << odd[i] << " ";
    }
    cout << endl;*/
    for (int i = 0; i < io; i++) {
        if (odd[i] >= even[i] && i + 1 < ie && odd[i] <= even[i+1]) {
            continue;
        } else if (i == io - 1 && ie == io && odd[i] >= even[i] ) {
            continue;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    if (ie == io + 1 && even[ie-1] < odd[io-1]) {
        cout << "NO" << endl;
        return;
    } 

    cout << "YES" << endl;
}  

int main () {
    int T;
    cin >> T;
    while (T--) {
        cin >> l;
        for (int i = 0; i < l; i++) {
            cin >> a[i];
        }
        solve();
    }
}