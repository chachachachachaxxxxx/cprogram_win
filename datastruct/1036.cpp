#include <stdio.h>
#define N 80

void replace(char s[], char x[], char y[]) { //TODO: your function definition
    int lenx, leny;
    lenx = leny = 0;
    while (x[lenx] != '\0')
        lenx++;
    while (y[leny] != '\0')
        leny++;

    int ls, lx, ly;
    ls = lx = ly = 0;
    int flag = 0;
    while (s[ls] != '\0')
    {
        flag = 0;
        lx = 0;
        if (s[ls] == x[lx])
        {
            int ix = 0;
            while (x[ix] != '\0')
                if (x[ix] != s[ls+ix])
                    break;
                else
                    ix++;
            
            if (ix == lenx)
                flag = 1;
        }
        if (flag == 1)
        {
            char temp[3 * N + 1];
            int i = 0;
            for (; s[i + ls + lenx] != '\0'; i++)
                temp[i] = s[i + ls + lenx];
            temp[i] = '\0';

            int j = 0;
            for (; j < leny; j++)
                s[ls + j] = y[j];

            int k = 0;
            for (; k < i; k++)
            {
                s[ls + j + k] = temp[k];
            }
            s[ls + j + k] = '\0';

            ls += leny - 1;
        }
        ls++;
    }
}

int main() {
    char s[3 * N + 1], x[N + 1], y[N + 1];
    scanf("%s%s%s", s, x, y);
    replace(s, x, y);
    printf("%s\n", s);
    return 0;
}