#include<stdio.h>
#include<math.h>
int main(){
    int n,a=0;
    scanf("%d", &n);
    if (n == 2|| n == 3 || n== 5 || n == 7 || n== 11){
        printf("Yes");
    } else if ( n == 1 || n % 2 == 0 || n == 9) {
        printf("No");
    } else {
        for (int i = 3; i <= sqrt(n);i = i + 2){
            if (n % i == 0){
                printf("No");
                ++a;
                break;
            }
        }
        if (!a){
            printf("Yes");
        }
    }
    return 0;
}