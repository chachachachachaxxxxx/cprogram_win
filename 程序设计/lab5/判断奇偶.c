#include<stdio.h>
int main(){
    unsigned long long n;
    scanf("%llu", &n);
    int y;
    y = n % 2;
    printf("%d", y);
    return 0;
}
