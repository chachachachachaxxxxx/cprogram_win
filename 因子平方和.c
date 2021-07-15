#include<stdio.h>
#include<math.h>
int main()
{
    int n,c,i,pnum,s,num;
    int p[pnum];
    num = s = 0;
    scanf("%d", &pnum);
    while (num < pnum){
        scanf("%d", &p[num]);
        ++num;
    }
    for (c = 0; c < pnum;++c){
        n = p[c];
        for (i = 2; i <= n / 2;++i){
            if (n % i==0)
                s = s + i * i;
        }
        printf("case #:%d\n", c);
        printf("%d\n", s);
        s = 0;
    }
}