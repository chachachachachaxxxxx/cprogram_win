#include<stdio.h>
#include<ctype.h>
int main(){
    char a,b;
    scanf("%c", &a);
    if (a >= 'a' && a <= 'z'){
        b = toupper(a);
    } else {
        b = a;
    }
    int c;
    c = b - 'A' + 1;
    printf("%d %d", a, c);
    return 0;
}