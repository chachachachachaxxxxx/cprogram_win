#include<stdio.h>
#include<math.h>

int hw_sf(int n)
{
    int a, j, s = 0, nb;
    nb = n;
    while (n > 0)
    {
        a = n % 10;
        s = s * 10 + a;
        n /= 10;
    }
    if (s==nb){
        j = 1;
    } else {
        j = 0;
    }
    return j;
}

int prime_sf(int n)
{
    int j, a = 0;
    if (n == 2|| n == 3 || n== 5 || n == 7 || n== 11){
        j = 1;
    } else if ( n == 1 || n % 2 == 0|| n % 3 == 0) {
        j = 0;
    } else {
        for (int i = 3; i <= sqrt(n);i = i + 2){
            if (n % i == 0){
                j = 0;
                a++;
                break;
            }
        }
        if(!a){
            j = 1;
        }
    }
    return j;
}

int weishu(int n)
{
    int i = 0;
    while (n>0)
    {
        n /= 10;
        i++;
    }
    return i;
}

int main()
{
    int a, b, hws_gs = 0,ws;
    scanf("%d\n%d", &a, &b);
    for (int i = a; i <= b;++i)
    {
        ws = weishu(i);
        switch(ws)
        {
            case 4:
                i = 10001;
                break;
            case 6:
                i = 1000001;
                break;
            case 8:
                i = 100000001;
                break;
            default:
                break;
        }
        if(hw_sf(i)&&prime_sf(i))
        {
            hws_gs++;
        }
    }
    printf("%d", hws_gs);
    return 0;
}