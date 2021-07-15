#include<stdio.h>
#include<math.h>
int main(){
    int pnums,i,j,ci4,n;
    scanf("%d",&pnums);
    int p[pnums];
    for (i = 0; i < pnums; ++i)
        scanf("%d", &p[i]);
    for (i = 0; i < pnums; ++i){
        n = p[i];
        for (j = 2; j <= n / 2; ++j){
            ci4 = 0;
            while (n % j == 0){
                n = n / j;
                ++ci4;
            }
            if (ci4 != 0)
                printf("(%d,%d)", j, ci4);
        }
        if (n != 1)
            printf("(%d,%d)",n,1);
        printf("\n");
    }
    return 0;
}