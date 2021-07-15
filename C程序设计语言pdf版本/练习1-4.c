#include<stdio.h>
int main()
{
    float fahr, celsius;
    int lower, upper, step;
    lower = -20;
    upper = 100;
    step = 5;
    celsius = lower;
    while (celsius <= upper)
    {
        fahr = celsius * 1.8 + 32;
        printf("%3.0f%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}