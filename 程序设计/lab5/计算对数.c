#include<stdio.h>
#include<math.h>
int main(){
    int b;
    double x, y;
    scanf("%d %lf", &b, &x);
    y = log(x) / log(b);
    printf("%.6lf", y);
    return 0;
}