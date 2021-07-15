#include<stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d", &a, &b);
    if(a < 0&& b<0)
        if (a%2==0||b%2==0)
        c = a / 2 + b / 2;
        else
        c = a / 2 + b / 2 -1;
    else if(a > 0 && b>0)
        if (a%2==0||b%2==0)
        c = a / 2 + b / 2;
        else
        c = a / 2 + b / 2 + 1;
    else
    c = (a + b) / 2;
    printf("%d", c);
    return 0;
}