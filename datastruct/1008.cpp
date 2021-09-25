#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1010;

int N, M;
int a[MAXN];

int quchong(int *a, int N)
{
    int M = 1;
    for (int i = 1; i < N; i++)
    {
        if (a[i] != a[i-1])
            a[M++] = a[i];
    }
    return M;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a + N);
    M = quchong(a, N);
    for (int i = 0; i < M; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}