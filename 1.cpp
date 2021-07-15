#include<cstdio>
#include<cmath>
#define max_n 50
using namespace std;

int main(){
    int pnums;
    scanf("%d", &pnums);
    int a[pnums][max_n+1];
    for (int i = 0; i < pnums; i = i + 1){
        scanf("%d", &a[i][0]);
        for (int e = 1; e < a[i][0];e = e + 1){
            scanf("%d ", &a[i][e]);
        }
    }
    for (int i = 0; i < pnums; i = i + 1){
        for (int e = 0; e < a[i][1];e = e + 1){
            printf("%d ", a[i][e]);
        }
    }
    return 0;
}