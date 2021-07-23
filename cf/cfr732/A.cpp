#include <iostream>
using namespace std;

const int MAXN = 110;
int l, sa, sb;
int a[MAXN];
int b[MAXN];
struct oper {
    int in;
    int de;
};
oper op[MAXN];

int arr_neq(int *a, int *b) {
    for (int i = 0; i < l; i++) {
        if (a[i] != b[i])
            return i;
    }
    return -1;
}

void solve() {
    if (sa != sb) {
        cout << -1 << endl;
        return;
    }

    int cnt = 0;
    int i = 0;
    while ((i = arr_neq(a, b)) != -1) {
        //cout << i;
        if (a[i] > b[i]) {
            for (int j = i + 1; j < l; j++) {
                if (a[j] < b[j]) {
                    op[cnt].de = i + 1;
                    op[cnt].in = j + 1;
                    a[i]--;
                    a[j]++;
                    break;
                }
            }
        } else {
            for (int j = i + 1; j < l; j++) {
                if (a[j] > b[j]) {
                    op[cnt].de = j + 1;
                    op[cnt].in = i + 1;
                    a[i]++;
                    a[j]--;
                    break;
                }
            }
        }
        cnt++;
    }

    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << op[i].de << " " << op[i].in << endl;
    }
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        cin >> l;
        sa = sb = 0;
        for (int i = 0; i < l; i++) {
            cin >> a[i];
            sa += a[i];
        }
        for (int i = 0; i < l; i++) {
            cin >> b[i];
            sb += b[i];
        }
        solve();
    }
}
