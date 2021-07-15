#include<stdio.h>
#include<math.h>
int qd(int a, int b){
    if (a <= b)
        return b;
    else
        return a;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[2*n+1][2*n+1];
    for (int i = 0; i < 2*n+1; ++i){
        for (int j = 0; j < 2*n+1; ++j){
            a[i][j] = qd(abs(i - n), abs(j - n));
        }
    }
    for (int i = 0; i < 2*n+1; ++i){
        for (int j = 0; j < 2*n+1; ++j){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
