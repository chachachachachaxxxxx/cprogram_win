#include <iostream>
#include <set>
using namespace std;

const int MAXX = 5;
const int MAXY = 5;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int matrix[MAXX][MAXY];
set<int> st;

void dfs(int x, int y, int n, int ci) {
    if (ci == 6) {
        st.insert(n);
        return;
    }
    n = n * 10 + matrix[x][y];
    for (int i = 0; i < 4; i++) {
        if (x+dx[i] >= 0 && x+dx[i] < MAXX && y+dy[i] >= 0 && y+dy[i] < MAXY)
            dfs(x + dx[i], y + dy[i], n, ci + 1);
    }
}

void solve() {
    for (int i = 0; i < MAXX; i++)
        for (int j = 0; j < MAXY; j++)
            dfs(i, j, 0, 0);
    printf("%llu\n", st.size());
}

int main() {
    for (int i = 0; i < MAXX; i++)
        for (int j = 0; j < MAXY; j++)
            scanf("%d", &matrix[i][j]);
    solve();
    return 0;
}