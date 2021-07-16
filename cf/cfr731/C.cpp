#include <iostream>
using namespace std;

const int MAXN = 310;

int a[MAXN];
int b[MAXN];
int c[MAXN * 2];
int l, al, bl;

void solve () {
    int ita, itb;
    ita = itb = 0;
    for (int i = 0; i < al + bl; i++) {
        if (ita < al && a[ita] <= l )
            c[i] = a[ita++];
        else if (itb < bl && b[itb] <= l)
            c[i] = b[itb++];
        else {
            cout << -1 << endl;
            return;
        }
        if (c[i] == 0)
            l++;
    }

    for (int i = 0; i < al + bl; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}

int main () {
    int cnum;
    cin >> cnum;
    while (cnum--) {
        cin >> l >> al >> bl;
        for (int i = 0; i < al; i++)
            cin >> a[i];
        for (int i = 0; i < bl; i++)
            cin >> b[i];
        /*for (int i = 0; i < al; i++)
            cout << a[i];
        for (int i = 0; i < bl; i++)
            cout << b[i];      */
        solve();
    }
}