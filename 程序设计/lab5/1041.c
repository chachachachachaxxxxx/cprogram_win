#include <stdio.h>

double sum(n)
{
    int sign = 1;
    if ( n % 2 == 0)
        sign = -1;
    if (n == 1)
        return 1;
    else
        return sum(n - 1) + sign * 1.0 / n;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%f\n",sum(n));
    return 0;
}