#include<stdio.h>
#include<math.h>
int main(){
    float d,p,r,m;
    scanf("%f %f %f",&d,&p,&r);
    m = log10(p/(p-d*r/100))/log10(1+r/100);
    printf("%.0f", m);
    return 0;
}