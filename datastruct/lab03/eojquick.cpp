#include <iostream>
using namespace std;
int N;
void print(int *a, int len)
{
    for (int i = 0; i < len - 1; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[len - 1]);
}

void swap(int *a, int m, int n)
{
    int k = a[m];
    a[m] = a[n];
    a[n] = k;
}

void quick_sort(int *a, int left, int right)
{
    if (left >= right)
        return;
    int low = left;
    int key = a[left];
    int up = right;
    while (low != up)
    {
        while (low < up && a[up] >= key)
            up--;
        if (low < up)
            a[low++] = a[up];
        while (low < up && a[low] <= key)
            low++;
        if (low < up)
            a[up--] = a[low];
    }
    a[low] = key;

    print(a, N);

    quick_sort(a, left, low - 1);
    quick_sort(a, low + 1, right);
}

int main()
{
    scanf("%d", &N);
    int *a = new int[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", a + i);
    }
    quick_sort(a, 0, N - 1);

    delete[] a;
}