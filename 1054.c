#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 210

int main()
{
    int n, len;
    char s[N];
    char *x, *y;
    scanf("%d",&n);
    for (int i = 0; i <n; i++)
    {
        scanf("%d",&len);
        scanf("%s",s);
        x = s;
        y = s + len - 1;
        if ((*x == '2' && *(x+1) == '0' && *(x+2) == '2' && *(x+3) == '0')
            ||(*x == '2' && *(x+1) == '0' && *(x+2) == '2' && *y == '0')
            ||(*x == '2' && *(x+1) == '0' && *(y-1) == '2' && *y == '0')
            ||(*x == '2' && *(y-2) == '0' && *(y-1) == '2' && *y == '0')
            ||(*(y-3) == '2' && *(y-2) == '0' && *(y-1) == '2' && *y == '0'))
            printf("Yes");
        else
            printf("No");
        printf("\n");
    }
    return 0;
}