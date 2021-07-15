#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d,i,c;
    c = 0;
    for (i=1000;i<=9999;++i){
        a = i / 1000;
        b = (i % 1000) / 100;
        c = (i % 100) / 10;
        d = i % 10;
        if (pow(a,4)+pow(b,4)+pow(c,4)+pow(d,4)==i){
            printf("%d\n",i);
            c = c + 1;
        }
    }
    if (c==0)
        printf("no answer");
     return 0;
}