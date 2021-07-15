#include <stdio.h>
#include <string.h>

int pnum[20050];
int s[200050];
int shu[200050];
int jie[20050];

int main()
{
    int pnums, min;
    scanf("%d", &pnums);
    memset(jie, -1, 20050);
    for (int i = 0; i < pnums;i++)
    {
        memset(shu, 0, 20050);
        min = 200000;
        scanf("%d", &pnum[i]);
        for (int j = 0; j < pnum[i];j++)
        {
            scanf("%d", &s[j]);
            shu[s[j]]++;
        }
        for (int j = 0; j < pnum[i];j++)
        {
            if (shu[s[j]] == 1 && s[j] < min)
            {
                min = s[j];
                jie[i] = j + 1;
            }
        }
    }
    for (int i = 0; i < pnums;i++)
    {
        printf("%d\n",jie[i]);
    }
    return 0;
}