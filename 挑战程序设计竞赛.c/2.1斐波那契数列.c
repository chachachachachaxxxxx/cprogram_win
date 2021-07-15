#include<stdio.h>
#define MAX_N 100
int memo[MAX_N + 1] = {0};

int fib(int n){
    if (n <= 1)
        return n;
    if (memo[n] != 0)
        return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}

int main(){
    printf("fib(50)=%d", fib(50));
    return 0;
}