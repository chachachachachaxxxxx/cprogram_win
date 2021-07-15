#include<stdio.h>
#include<math.h>

int prime_shifou(int n){
    if (n == 2|| n == 3 || n== 5 || n == 7 || n== 11){
        return 1;
    } else if ( n == 1 || n % 2 == 0 || n == 9) {
        return 0;
    } else {
        for (int i = 3; i <= sqrt(n);i = i + 2){
            if (n % i == 0){
                return 0;
            }
        }
        return 1;
    }
}

int main(){
    int a, b, hw_geshu = 0, e = 0;
    scanf("%d\n%d", &a, &b);
    int hw[100009];
    for (int i = 0; i < 10;i++)
    {
        hw[e] = i;
        e++;
    }
    for (int i = 11; i < 100; i +=11)
    {
        hw[e] = i;
        e++;
    }
    for (int i = 1; i < 10;i++)
    {
        for (int j = 0; j < 10;j++)
        {
            hw[e] = i * 100 + j * 10 + i;
            e++;
        }
    }
    for (int i = 1; i < 10;i++)
    {
        for (int j = 0; j < 10;j++)
        {
            for (int k = 0; k < 10;k++)
            {
                hw[e] = i * 10000 + j * 1000 + k * 100 + j * 10 + i;
                e++;
            }
        }
    }
    for (int i = 1; i < 10;i++)
    {
        for (int j = 0; j < 10;j++)
        {
            for (int k = 0; k < 10;k++)
            {
                for (int l = 0; l < 10;l++)
                {
                    hw[e] = i * 1000000 + j * 100000 + k * 10000 + l * 1000 + k * 100 + j * 10 + i;
                    e++;
                }
            }
        }
    }
    for (int i = 1; i < 10;i++)
    {
        for (int j = 0; j < 10;j++)
        {
            for (int k = 0; k < 10;k++)
            {
                for (int l = 0; l < 10;l++)
                {
                    for (int m = 0; m < 10;m++)
                    {
                        hw[e] = i * 100000000 + j * 10000000 + k * 1000000 + l * 100000 + m * 10000 + l * 1000 + k * 100 + j * 10 + i;
                        e++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 100009;i++)
    {
        if(prime_shifou(hw[i])&&a <= hw[i]&&hw[i]<=b)
        {
            hw_geshu++;
        }
    }
    printf("%d", hw_geshu);
    return 0;
}