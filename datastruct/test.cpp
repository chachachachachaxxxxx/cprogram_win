#include <iostream>
using namespace std;

const int MAXSIZE = 100;

int insert(int *a, int &n, int i, int x)
{
    if (i < 0 || i > n)
        return 1;
    if (n == MAXSIZE)
        return 2;
    for (int j = n; j > i; j--)
    {
        a[j] = a[j - 1];
    }
    a[i] = x;
    (n)++;
    return 0;
}

int main()
{
    int list[MAXSIZE] = {};
    int n = 10;
    insert(list, n, 5, 5);
    printf("%d\n", n);
    return 0;
}