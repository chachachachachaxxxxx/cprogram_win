#include<stdio.h>
#include<math.h>
int main()
{
    float a,b;
    while (scanf("%.0f %.0f\n",&a,&b)!=EOF)
    printf("%.3f\n",sqrt(a*a+b*b));
    return 0;
}