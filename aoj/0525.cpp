#include <iostream>
#include <cstring>
using namespace std;

const int MAXR = 10;
const int MAXC = 10000;

int matrix[MAXR][MAXC];
int r, c;
int ans;

void dfs(int ir) {
    if (ir == r) {
        int ans1 = 0;
        for (int i = 0; i < c; i++) {
            int s = 0;
            for (int j = 0; j < r; j++)
                s += matrix[j][i];
            s = max(s, r - s);
            ans1 += s;
        }
        ans = max(ans, ans1);
        return;
    }
    dfs(ir + 1);
    for (int i = 0; i < c; i++) {
        if (matrix[ir][i] == 1)
            matrix[ir][i] = 0;
        else
            matrix[ir][i] = 1;
    }
    dfs(ir + 1);
} 

void solve() {
    //printf("%d %d\n", r, c);
    dfs(0);
    printf("%d\n", ans);
}

int main() {
    while (scanf("%d %d\n", &r, &c) && !(r == 0 && c == 0)) {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                scanf("%d", &matrix[i][j]);
        solve();
    }
    return 0;
}