#include<stdio.h>
int power(int n, int m);
int main()
{
    int i, c;
    c = 10;
    for (i = 1; i <= c; ++i){
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }
    return 0;
}
int power(int base, int n)
{
    int i,p;
    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}