#include <stdio.h>
#include <stdlib.h>

int pnum[20050];
int p[200050];
int jie[20050];

int zuix(int a[], int len);

int main()
{
    int pnums;
    scanf("%d", &pnums);
    for (int i = 0; i < pnums; i++)
    {
        scanf("%d", &pnum[i]);
        for (int j = 0; j < pnum[i];j++)
        {
            scanf("%d", &p[j]);
        }
        jie[i] = zuix(p, pnum[i]);
    }
    for (int i = 0; i < pnums; i++)
    {
        printf("%d\n", jie[i]);
    }
    return 0;
}

int zuix(int a[],int len)
{
    int jie = -2;
    int guo = len;
    int tong;
    for (int i = 0; i < len;i++)
    {
        if (a[i] == 0)
            continue;
        if (i == 0)
        {
            jie = i;
            guo = a[i];
        }
        else
        {
            if (a[i] > guo)
                continue;
            else if (a[i] < guo)
            {
                jie = i;
                guo = a[i];
            }
            else
            {
                tong = a[i];
                for (int j = i; j < len; j++)
                {
                    if (a[j] == tong)
                        a[j] = 0;
                }
                i = jie;
                jie = -2;
                guo = len;
            }
        }
    }
    jie++;
    return jie;
}
