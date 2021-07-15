#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* Number2Alpha(int num);

char s[20];

int main()
{
    int n;
    char *k;
    scanf("%d",&n);
    k = Number2Alpha(n);
    printf("%s", k);
    return 0;
}

char* Number2Alpha(int num)
{
    char *p;
    p = s;
    switch (num)
    {
    case 1:
        strcpy(s, "January");
        return p;
    case 2:
        strcpy(s, "February");
        return p;
    case 3:
        strcpy(s, "March");
        return p;
    case 4:
        strcpy(s, "April");
        return p;
    case 5:
        strcpy(s, "May");
        return p;
    case 6:
        strcpy(s, "June");
        return p;
    case 7:
        strcpy(s, "July");
        return p;
    case 8:
        strcpy(s, "August");
        return p;
    case 9:
        strcpy(s, "September");
        return p;
    case 10:
        strcpy(s, "October");
        return p;
    case 11:
        strcpy(s, "November");
        return p;
    case 12:
        strcpy(s, "December");
        return p;
    }
}
