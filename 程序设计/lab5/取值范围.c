#include<stdio.h>
#include<limits.h>

int main(){
    printf("%d %d\n", CHAR_MIN, CHAR_MAX);  //char, int, unsigned int, short int, long long, unsigned long long
    printf("%d %d\n", INT_MIN, INT_MAX);
    printf("%u %u\n", 0, UINT_MAX);
    printf("%d %d\n", SHRT_MIN, SHRT_MAX);
    printf("%lld %lld\n", LLONG_MIN, LLONG_MAX);
    printf("%llu %llu\n", 0,ULLONG_MAX);
    return 0;
}