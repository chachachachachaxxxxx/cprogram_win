#include <iostream>
using namespace std;
const int MAXN = 3e7 + 10;

int maxheap[MAXN];
int N, M;

void siftdown(int *a, int i, int n)
{
    int j, t;
    t = a[i];
    while ((j = 2 * i + 1) < n)
    {
        if (j < n-1 && a[j] < a[j+1])
            j++;
        if (t < a[j])
        {
            a[i] = a[j];
            i = j;
        }
        else
            break;
    }
    a[i] = t;
}

void buildheap(int *a, int n)
{
    int i;
    for (i = (n - 2) / 2; i >= 0; i--)
        siftdown(a, i, n);
}

void heap_sort(int *a, int n, int m1)
{
    int m, t;
    for (m = n - 1; m >= n - m1; m--)
    {
        t = a[0];
        a[0] = a[m];
        a[m] = t;
        siftdown(a, 0, m);
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        scanf("%d", maxheap + i);
    buildheap(maxheap, N);
    if (M > N)
        M = N;

    heap_sort(maxheap, N, M);
    for (int i = N - 1; i >= N - M; i--)
    {
        cout << maxheap[i] << " ";
    }
    cout << endl;
}