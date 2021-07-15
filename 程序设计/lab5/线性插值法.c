#include<stdio.h>

int main(){
    double a, fa, b, fb, c, fc;
    scanf("%lf %lf %lf %lf %lf", &a, &fa, &b, &fb, &c);
    fc = (fa - fb) / (a - b) * (c - b) + fb;
    printf("%.3lf", fc);
    return 0;
}