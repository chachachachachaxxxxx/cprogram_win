#include<stdio.h>
#include<math.h>
int main(){
    
    int c,b,shu;
    scanf("%d\n%d", &c,&b);
    int a[b+1];
    int shuwei[10];
    a[0] = a[1] = 0;
    for (int i = 2; i <= b;++i){
        a[i] = i;
    }
    int e, s, hw_geshu = 0;
    for (int i = 2; i <= b ;++i){
        e = 0;
        s = 0;
        if (a[i]){
            for (int j = i*i; j <= b;j = j + i ){
                a[j] = 0;
            }
            shu = i;
            while(shu > 0){
                shuwei[e] = shu % 10;
                shu /= 10;
                ++e;
            }
            for (int h = 0; h < e;++h){
                s = s * 10 + shuwei[h];
            }
            if(i == s && i >= c){
                hw_geshu++;
            }
        }
    }
    printf("%d", hw_geshu);
    return 0;
}