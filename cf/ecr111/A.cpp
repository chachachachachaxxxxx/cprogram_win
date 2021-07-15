#include <iostream>
#include <cmath>
using namespace std;

int casenum;
int sum;

void solve() {
    double a = sqrt(double(sum));
    int ans = int(a);
    if (ans * ans < sum)
        ans++;
    printf("%d\n", ans);
}

int main() {
    scanf("%d\n", &casenum);
    for (int i = 0; i < casenum; i++) {
        scanf("%d\n", &sum);
        solve();
    }
    return 0;
}