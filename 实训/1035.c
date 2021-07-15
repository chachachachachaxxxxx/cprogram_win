#include <stdio.h>
#include <stdlib.h>
#define MAXN 1001

typedef struct yz{
    int r;
    int h;
    int xs;
} YX;

YX yzs[MAXN];
int da[MAXN];

int cmp(const void*a, const void*b)
{
    YX *a1, *b1;
    a1 = (YX *)a;
    b1 = (YX *)b;
    return b1->r - a1->r;
}

int cmp1(const void*a, const void*b)
{
    YX *a1, *b1;
    a1 = (YX *)a;
    b1 = (YX *)b;
    return a1->xs - b1->xs;
}

int main()
{
    int n, m, d;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &(yzs + i)->r, &(yzs + i)->h);
        (yzs + i)->xs = 2 * (yzs + i)->r * (yzs + i)->h;
    }
    YX *yzx;
    yzx = (YX *)malloc(sizeof(YX) * m);
    qsort(yzs, n, sizeof(YX), cmp);
    da[0] = yzs->xs + yzs->r * yzs->r;
    yzx[0].h = yzs[0].h;
    d = yzx[0].r = yzs[0].r;
    yzx[0].xs = yzs[0].xs;
    qsort(yzs+1, n-1, sizeof(YX), cmp1);
    for (int i = 1; i < m; i++)
    {
        da[i] = da[i - 1] + yzs[i].xs;
        yzx[i].h = yzs[i].h;
        yzx[i].r = yzs[i].r;
        yzx[i].xs = yzs[i].xs;
    }
    printf("%d", da[m - 1]);
    return 0;
}