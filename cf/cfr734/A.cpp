#include <iostream>
using namespace std;

int val;
int c1, c2;

void solve() {
    c1 = c2 = 0;
    c1 = val / 3;
    if (val - 3 * c1 == 2) {
        c2 = c1 + 1;
    } else if (val - 3 * c1 == 1) {
        c2 = c1;
        c1++;
    } else {
        c2 = c1;
    }
    printf("%d %d\n", c1, c2);
}

int main() {
    int T;
    scanf("%d\n", &T);
    while (T--) {
        scanf("%d\n", &val);
        solve();
    }
}