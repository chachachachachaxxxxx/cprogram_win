#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;++i){
        for (int e = 1; e <= i;++e){
            printf("%d ", e);
        }
        printf("\n");
    }
    return 0;
}