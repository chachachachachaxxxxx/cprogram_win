#include<cstdio>
#include<cmath>
#define max_n 50
using namespace std;

int main(){
    int pnums;
    scanf("%d", &pnums);
    int a[pnums][max_n];
    for (int i = 0; i < pnums; i = i + 1){
        scanf("%d", &a[i][0]);
        for (int e = 0; e < a[i][1];e = e + 1){
            scanf("%d", &a[i][e]);
        }
    }
    int b[max_n];
    int step,s,min,index,geshu0;
    for (int i = 0; i < pnums; i = i + 1){
        step = 0;
        for (int j = 1; j < a[i][0] ; j = j + 1){
            if (a[i][j] == 1){
                b[step] = j;
                step = step + 1;
            }
        }
        min = 1225;
        for (int e = 0; e < step;e = e + 1){
            s = 0;
            for (int f = 0; f < step;++f){
                s = abs(b[e] - b[f]) + s;
            }
            if (s < min){
                min = s;
                index = b[e];
            }
        }
        geshu0 = 0;
        for (int e = 0; e < step;++e){
            if (b[e] < index){
                for (int f = b[e]+1; f < index ; ++f){
                    if (a[i][f]==0)
                        geshu0 = geshu0 + 1;
                }
            }
            else if(b[e] > index){
                for (int f = b[e]-1; f > index ; --f){
                    if (a[i][f]==0)
                        geshu0 = geshu0 + 1;
                }
            }
        }
        printf("%d", geshu0);
    }
    return 0;
}