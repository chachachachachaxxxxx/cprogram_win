#include<stdio.h>
int main(){
    int a,b;
    scanf("%d",&a);
    if (a % 400 == 0||(a % 4 == 0 && a % 100 != 0))
        b = 1;
    else
        b = 0;
    printf("%d",b);
    return 0;
}