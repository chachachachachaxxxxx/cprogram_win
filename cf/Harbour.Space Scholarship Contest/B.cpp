#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 1010;
string s;
string d;

void solve() {
    int n;
    for (int i = 0; i <= (int)d.length(); i++) {
        string d2(d, 0, i);
        string d3(d, i, d.length() - i);
        
        reverse(d3.begin(), d3.end());
        //cout << d2 << " " << d3 << endl;
        if (i == 0) {
            n = s.find(d3);
            if (n != string::npos) {
                printf("YES\n");
                return;
            }
        } else if (i == (int)(d.length())) {
            n = s.find(d2);
            if (n != string::npos) {
                printf("YES\n");
                return;
            }
        } else {
        n = s.find(d2);
        while (n != string::npos) {
            if (n + i - 1 >= d3.length()) {
                int k = n + i - 2;
                int sign = 1;
                for (int j = d3.length() - 1; j >= 0 && k >= 0; j--, k--) {
                    if (d3[j] != s[k]) {
                        sign = 0;
                        break;
                    }
                }
                if (sign) {
                    printf("YES\n");
                    return;
                }
            }
            n = s.find(d2, n + 1);
        }
        }
    }
    printf("NO\n");
}

int main() {
    int T;
    scanf("%d\n", &T);
    while (T--) {
        cin >> s >> d;
        solve();
    }
}