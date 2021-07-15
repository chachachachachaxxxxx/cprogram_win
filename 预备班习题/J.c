#include<stdio.h>
#include<math.h>
int main(){
    int n;
    scanf("%d", &n);
    int a[n][n];
    int x, y,step=1;
    a[0][n - 1] = 1;
    if (n >= 2){
        x = n - 2;
        y = 0;
        for (int i = 2; i <= n * n; ++i)
        {   
            if ( 0 <= x <= n-1 && 0 <= y <= n-1)
            {
                a[y][x] = i;
                x = x + 1;
                y = y + 1;
            }
            if (x == n)
            {
                x = n - (y + 1);
                y = 0;
            }
            if (x < 0 || y == n)
            {
                x = 0;
                y = step;
                step = step + 1;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}