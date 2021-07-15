#include<stdio.h>
int main(){
    int n, s, p, y;
    scanf("%d %d %d", &n, &s, &p);
    y = n % 100;
    if (s >= 10){
        if (p >= 10)
            printf("%02d%d%d", y, s, p);
        else 
            printf("%02d%d0%d", y, s, p);    
    }
    else{
        if (p >= 10)
            printf("%02d0%d%d", y, s, p);
        else 
            printf("%02d0%d0%d", y, s, p); 
    }
    return 0;
}