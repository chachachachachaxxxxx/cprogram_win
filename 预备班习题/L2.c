#include<stdio.h>
#include<math.h>
int main(){
    int n;
    scanf("%d", &n);
    int a[n][n];
    int b[2 * n - 1];
    int c = 1,step = 0;
    for (int i = 0; i < 2 * n - 1; ++i){
        c = c + step;
        b[i] = c;
        if (i <= n-1)
            step = step + 1;
        else
            step = step - 1;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j){
            if (i+j <= n-1){
                if ((i+j) % 2 == 0){
                    a[i][j] = b[i + j] + i;
                }
                else{
                    a[i][j] = b[i + j] + j;
                }
            }
            else{
                if ((i+j) % 2 == 0){
                    a[i][j] = b[i + j] + n-1 - j;
                }
                else{
                    a[i][j] = b[i + j] + n-1 - i;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}