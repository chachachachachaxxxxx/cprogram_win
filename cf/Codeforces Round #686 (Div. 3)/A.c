#include <stdio.h>

int a[105];

int main()
{
    int pnum;
    scanf("%d", &pnum);
    for (int i = 0; i < pnum; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < pnum; i++)
    {
        for (int j = 1; j <= a[i];j++)
        {
            if (j == 1)
                printf("%d", a[i]);
            else
            {
                printf(" %d", j - 1);
            }
        }
        printf("\n");
    }
    return 0;
}