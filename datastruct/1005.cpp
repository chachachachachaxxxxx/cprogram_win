#include <iostream>
using namespace std;
const int MAXN = 1010;

int m, n;
int A[MAXN], B[MAXN];

int cmp(int *A, int *B, int m, int n)
{
    int l = m > n ? n : m;
    for (int i = 0; i < l; i++)
    {
        if (A[i] < B[i])
            return -1;
        else if (A[i] > B[i])
            return 1;
    }
    if (m > n)
        return 1;
    else if (m < n)
        return -1;
    return 0;
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
        cin >> B[i];
    cout << cmp(A, B, m, n);
    return 0;
}