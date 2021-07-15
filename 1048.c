#include <stdio.h>
#include <stdlib.h>

int find_min(int *a, int len)
{
    int mx=0;
    for(int i = 0; i < len; i++)
    {
        if (*(a+i) < *(a+mx))
            mx = i;
    }
    return mx;
}

int deng(int *a, int len)
{
    for(int i = 0; i < len; i++)
    {
        if(*(a+i)!=*a)
            return -1;
    }
    return 1;
}

void add2l(int *a, int len, int mx)
{
    *(a+mx-1) = *(a+mx-1) + *(a+mx);
    for(int i = 0; i < len - mx - 1; i++)
    {
        *(a+mx+i) = *(a+mx+i+1);
    }
}

void add2r(int *a, int len, int mx)
{
    *(a+mx+1) = *(a+mx+1) + *(a+mx);
    for(int i = 0; i < len - mx - 1; i++)
    {
        *(a+mx+i) = *(a+mx+i+1);
    }
}

int f(int *a, int len)
{
    int len1 = len;
    int cs = 0, mx;
    while(!deng(a, len1))
    {
        mx = find_min(a, len1);
        if (mx == 0 || *(a+mx-1) >= *(a+mx+1))
        {
            add2r(a, len1, mx);
            len1 -= 1;
            cs++;
            continue;
        }
        if (mx == len1-1 || *(a+mx-1) < *(a+mx+1))
        {
            add2l(*a, len1, mx);
            len1 -= 1;
            cs++;
            continue;
        }
    }
    return cs;
}

int main()
{
    int n;
    scanf("%d", &n);
    int len, cs;
    int *a;
    for (int i = 0 ; i < n; i++)
    {
        scanf("%d",&len);
        a = (int*)malloc(len*sizeof(int));
        for(int j = 0;j < len; j++)
            scanf("%d",a+j);
        cs = f(a, len);
        printf("%d\n", cs);
    }
    return 0;
}