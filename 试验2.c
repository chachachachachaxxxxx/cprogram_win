#include <stdio.h>
int main()
{
    char s[100];
    while( scanf("%s", s) != '\n')
        printf("%s\n",s);
    return 0;
}