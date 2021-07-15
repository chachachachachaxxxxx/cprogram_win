#include<stdio.h>
int main(){
    int y, n, s, p;
    scanf("%d %d %d", &n, &s, &p);
    y = n % 100;
    printf("%02d%02d%02d", y, s, p);
    return 0;
}