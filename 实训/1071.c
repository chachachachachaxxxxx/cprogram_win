#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000

typedef struct bint{
    int num[1000];
    int len;
}   BI;

char s1[MAXN];
char s2[MAXN];

BI bint1, bf1, bint2, bf2;

void zhuan(char *s, BI *in, BI *fl)
{
    int i1 = strlen(s) - 1;
    int l = 0;
    while (s[i1] != '.' && i1 > 0)
    {
        fl->num[l++] = s[i1] - '0';
        i1--;
    }
    i1--;
    if (i1 == -1 && s[i1+1] != '.')
    {
        i1 = strlen(s) - 1;
        memset(fl->num, 0, sizeof(fl->num));
        fl->len = 0;
    }
    else 
    fl->len = l;
    l = 0;
    while (i1 >= 0)
    {
        in->num[l++] = s[i1] - '0';
        i1--;
    }
    if (l >= 1 && in->num[l-1] == 0)
    {
        while (in->num[--l] == 0)
            ;
        l++;
    }
    
    in->len = l;
}

void jia(BI *a, BI *b)
{
    int len = a->len > b->len ? a->len : b->len;
    int jw = 0;
    int i = 0;
    while (i < len)
    {
        a->num[i] += b->num[i] + jw;
        //printf("%d: %d %d\n", i, a->num[i], b->num[i]);
        if (a->num[i] >= 10)
        {
            a->num[i] -= 10;
            jw = 1;
        }
        else
            jw = 0;
        i++;
    }
    if (jw == 1)
    {
        a->num[len++] = 1;
    }
    a->len = len;
}

void jiaf(BI *a, BI *b)
{
    int len = a->len > b->len ? a->len : b->len;
    int d1 = len - a->len;
    int d2 = len - b->len;
    for (int i = len - 1; i >= 0; i--)
    {
        if (i - d1 >= 0)
            a->num[i] = a->num[i - d1];
        else
            a->num[i] = 0;
        if (i - d2 >= 0)
            b->num[i] = b->num[i - d2];
        else
            b->num[i] = 0;
    }
    jia(a, b);
}

int main()
{
    int jd;
    scanf("%s %s %d", s1, s2, &jd);
    zhuan(s1, &bint1, &bf1);
    //for (int i = bint1.len-1; i >= 0; i--)
    //    printf("%d", bint1.num[i]);
    //printf("\n");
    zhuan(s2, &bint2, &bf2);
    jia(&bint1, &bint2);
    int flen = bf1.len > bf2.len ? bf1.len : bf2.len;
    jiaf(&bf1, &bf2);
    int flen1 = bf1.len;
    //printf("%d\n", flen);
    if (jd < flen)
    {
        //printf("%d\n", bf1.num[flen - jd]);
        if (bf1.num[flen-jd-1] >= 5)
        {
            BI dan;
            memset(dan.num, 0, sizeof(dan.num));
            if (flen1 > flen)
                dan.len = jd + 1;
            else
                dan.len = jd;
            dan.num[0] = 1;
            jiaf(&bf1, &dan);
            //printf("\n");
        }
    }
    flen1 = bf1.len;
    /*for (int i = flen - 1; i >= 0; i--)
        printf("%d", bf1.num[i]);
    printf("\n");*/
    if (flen1 > flen)
    {
        BI dan;
        memset(dan.num, 0, sizeof(dan.num));
        dan.num[0] = bf1.num[flen1 - 1];
        dan.len = 1;
        jia(&bint1, &dan);
    }
    for (int i = bint1.len-1; i >= 0; i--)
        printf("%d", bint1.num[i]);
    if (bint1.len == 0)
        printf("0");
    printf(".");
    
    while (jd--)
    {
        if (flen >= 0)
            printf("%d", bf1.num[--flen]);
        else
            printf("0");
    }
    printf("\n");
    return 0;
}