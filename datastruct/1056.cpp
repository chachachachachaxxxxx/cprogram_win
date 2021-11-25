#include <iostream>
using namespace std;
const int MAXN = 51;

int a[MAXN];

int main()
{
    int N;
    scanf("%d", &N);
    int k;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &k);
        a[k]++;
    }

    for (int i = 0; i < MAXN; i++)
    {
        if (a[i] != 0)
            printf("%d:%d\n", i, a[i]);
    }
}