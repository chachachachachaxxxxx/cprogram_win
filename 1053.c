#include <stdio.h>
#include <stdlib.h>

#define LEN 80
void Sort(char (*a)[LEN+1], int n);

int main()
{
    int n;
    char a[11][81];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s",a[i]);
    }
    Sort(a, n);
    for(int i = 0; i < n; i++)
    {
        printf("%s\n",a[i]);
    }
    return 0;
}

int cmp(char *m, char *n)
{
    return strcmp(m, n);
}

void Sort(char (*a)[LEN+1], int n)
{
    qsort(a, n, LEN+1, cmp);
}