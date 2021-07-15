#include<cstdio>
using namespace std;
int main(){
    int pnums;
    scanf("%d", &pnums);
    int a[pnums];
    for (int i = 0; i < pnums; i = i + 1)
        scanf("%d", &a[i]);
    int ws, s = 0, fjh, ai, step;
    for (int i = 0; i < pnums; i = i + 1){
        s = 0;
        ws = a[i] % 10;
        s = s + (ws - 1) * 10;
        ai = 0;
        fjh = a[i];
        step = 1;
        while (fjh > 0){
            fjh = fjh / 10;
            ai = ai + step;
            step = step + 1;
        }
        s = s + ai;
        printf("%d\n", s);
    }
    return 0;
}