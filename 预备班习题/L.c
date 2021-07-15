#include<stdio.h>
#include<math.h>
int xingdong_x(int a,int c){
    if (c == 1 || c == 3){
        a = a + 1;
    }
    if (c == 2){
        a = a - 1;
    }
    return a;
}

int xingdong_y(int b , int c){
    if (c == 0 || c == 2)
        b = b + 1;
    if (c == 1)
        b = b - 1;
    return b;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n][n];
    int x = 0, y = 0;
    a[y][x] = 1;
    if (n>=2){
        y = xingdong_y(y, 0);
        x = xingdong_x(x, 0);
        a[y][x] = 2;
        int zt = 1;       // 0代表下行，1代表右上行，2代表左下行，3代表右行
        for (int i = 3; i <= n * n; ++i)
        {
            x = xingdong_x(x, zt);
            y = xingdong_y(y, zt);
            while (!(0 <= x && x <= n - 1 && 0 <= y && y <= n - 1))
            {
                if (zt == 1)
                {
                    zt = 0;
                    x = xingdong_x(x, zt);
                    y = xingdong_y(y, zt);
                }
                else if (zt == 2)
                {
                    zt = 3;
                    x = xingdong_x(x, zt);
                    y = xingdong_y(y, zt);
                }
                else if (zt == 0)
                    {
                        zt = 2;
                        x = xingdong_x(x, zt);
                        y = xingdong_y(y, zt);
                    }
                else if (zt == 3)
                {
                    zt = 1;
                    x = xingdong_x(x, zt);
                    y = xingdong_y(y, zt);
                }
            }
            a[y][x] = i;
            if (i <= (n*n) / 2)
            {
                if (zt == 0)
                    zt = 2;
                if (zt == 3)
                    zt = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}