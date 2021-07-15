#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 500020
#define N 10020

typedef struct
{
    char *s;
    int count;
    int slen;
} WORDS;

WORDS w[N];
char a[M];

int cmp(WORDS *a, WORDS *b)
{
    char *a1, *b1;
    a1 = a->s;
    b1 = b->s;
    return strcmp(a1, b1);
}

int main()
{
    int n = 0;
    int state = 0;
    int len = 0;
 /*   int len1;
    int first = 1;*/
    while(scanf("%s",a) != EOF)
    {
        len = strlen(a);
       /* if (first)
        {
            len1 = (M+len) / len;
            w = (WORDS*)malloc(len1*sizeof(WORDS));
            first = 0;
        }*/
        w[n].s = (char*)malloc(len*sizeof(char));
        for (int i= 0; i < n; i++)
        {
            if (strcmp(a, w[i].s) == 0)
            {
                w[i].count++;
                state = 1;
                break;
            }
        }
        if (!state)
        {
            strcpy(w[n].s, a);
            w[n].count = 1;
            w[n].slen = len;
            n++;
        }
        state = 0;
    }
    qsort(w, n, sizeof(WORDS), cmp);
    for (int i = 0 ;i < n; i++)
    {
        printf("%s %d\n", w[i].s, w[i].count);
        free(w[i].s);
    }
    free(w);
    return 0;
}