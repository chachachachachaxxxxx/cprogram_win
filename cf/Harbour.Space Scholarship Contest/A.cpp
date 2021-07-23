#include <iostream>
using namespace std;

int n;

int sum(int x) {
    int s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

void solve() {
    int t = 0;
    if (n % 10 == 9)
        t = 1;
    printf("%d\n", n / 10 + t);
}

int main() {
    int T;
    scanf("%d\n", &T);
    while (T--) {
        scanf("%d\n", &n);
        solve();
    }
}