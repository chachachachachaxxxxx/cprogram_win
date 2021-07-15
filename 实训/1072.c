#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000

typedef struct bint{
    int num[MAXN];
    int sign;
    int len;
} BI;

char shua[MAXN];
char shub[MAXN];

BI bi1, bi2, bi3;

void prs(BI a);

void zhuan(char *s, BI *a)
{
    int len = strlen(s) - 1;
    int l = 0;
    while (len >= 0)
        a->num[l++] = s[len--] - '0';
    a->len = l;
    a->sign = 1;
}

void jian(BI *a, BI *b, BI *c)
{
    int len = a->len > b->len ? a->len : b->len;
    for (int i = 0; i < len; i++)
    {
        c->num[i] = a->num[i] - b->num[i];
        if (c -> num[i] < 0)
        {
            a->num[i + 1]--;
            c->num[i] += 10;
        }
        //printf("%d", c->num[i]);
    }
    //printf("\n");
    if (a->num[len] == -1)
    {
        BI a1, c1;
        memset(a1.num, 0, sizeof(a1.num));
        memset(c1.num, 0, sizeof(c1.num));
        c1.len = len;
        for (int i = 0; i < len; i++)
            c1.num[i] = c->num[i];
        a1.num[len] = 1;
        a1.len = len + 1;
        for (int i = 0; i < len; i++)
            a1.num[i] = 0;
        //prs(a1);
        //prs(c1);
        jian(&a1, &c1, c);
        c->sign = -1;
        return;
    }
    else
        c->sign = 1;
    int l = len;
    while (c->num[--l] == 0)
        ;
    c->len = l + 1;
}

void prs(BI a)
{
    for (int i = a.len - 1; i >= 0; i--)
        printf("%d", a.num[i]);
    printf("\n");
}

void chushihua()
{
    memset(bi1.num, 0, sizeof(bi1.num));
    memset(bi2.num, 0, sizeof(bi2.num));
    memset(bi3.num, 0, sizeof(bi3.num));
}

int main()
{
    while (scanf("%s %s\n", shua, shub) != EOF)
    {
        if (shua[0] == EOF)
            break;
        chushihua();
        zhuan(shua, &bi1);
        zhuan(shub, &bi2);
        //for (int i = bi2.len - 1; i >= 0; i--)
        //    printf("%d", bi2.num[i]);
        //printf("\n");
        jian(&bi1, &bi2, &bi3);
        //printf("\n");
        if (bi3.sign == -1)
            printf("-");
        if (bi3.len <= 0)
            printf("0");
        else
        for (int i = bi3.len - 1; i >= 0; i--)
            printf("%d", bi3.num[i]);
        printf("\n");
    }
    return 0;
}
