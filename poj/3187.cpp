#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 11;

int N;
int sum;
int a[MAXN];

int factor(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factor(n - 1);
}

int combination(int n, int m) {
    if (m == 0 || m == n)
        return 1;
    return factor(n) / (factor(n - m) * factor(m));
}

int summing(int* a) {
    int s = 0;
    for (int i = 0; i < N; i++) {
        s += a[i] * combination(N - 1, i);
    }
    return s;
}

void solve() {
    for (int i = 1; i <= N; i++) {
        a[i - 1] = i;
    }
    do {
        if (summing(a) == sum)
            break;
    } while (next_permutation(a, a + N));

    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main() {
    scanf("%d %d\n", &N, &sum);
    solve();
    return 0;
}