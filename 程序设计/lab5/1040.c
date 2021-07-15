#include <stdio.h>

char jian(int a , int i)
{
    char c;
    switch (a)
    {
        case 0:
            c = '0';
            break;
        case 1:
            c = '1';
            break;
        case 2:
            c = 'A' + i;
            break;
        case 3:
            c = 'D' + i;
            break;
        case 4:
            c = 'G' + i;
            break;
        case 5:
            c = 'J' + i;
            break;
        case 6:
            c = 'M' + i;
            break;
        case 7:
            if(i > 0)
                i++;
            c = 'P' + i;
            break;
        case 8:
            c = 'T' + i;
            break;
        case 9:
            c = 'W' + i;
            break;
    }
    return c;
}

int keneng(int a)
{
    if (a == 0 || a == 1)
        return 1;
    return 3;
}

int main()
{
    char s[3];
    int a[3];
    scanf("%s", s);
    for (int i = 0; i < 3;i++)
        a[i] = s[i] - '0';
    int num1, num2, num3, num;
    num1 = keneng(a[0]);
    num2 = keneng(a[1]);
    num3 = keneng(a[2]);
    num = num1 * num2 * num3;
 /*   for (int n = 0; n < num; n++)
    {
        i = n % (num2 * num3);
        printf("%c", jian(a[0], i));
        j = (n / num1) % 3;
        printf("%c", jian(a[1], j));
        k = n % 3;
        printf("%c", jian(a[2], k));
        printf("\n");
    }*/
    for (int n1 = 0; n1 < num1; n1++)
    {
        for (int n2 = 0; n2 < num2; n2++)
        {
            for (int n3 = 0; n3 < num3; n3++)
            {
                printf("%c", jian(a[0], n1));
                printf("%c", jian(a[1], n2));
                printf("%c\n", jian(a[2], n3));
            }
        }
    }
    return 0;
}