#include <iostream>
using namespace std;
const int MAXN = 1e6 + 10;

int a[MAXN][3];
int b[MAXN][3];
int c[2 * MAXN][3];

void add(int a[][3], int b[][3], int c[][3])
{
    int i, j, k;
    i = j = k = 1;
    c[0][0] = a[0][0] > b[0][0] ? a[0][0] : b[0][0];
    c[0][1] = a[0][1] > b[0][1] ? a[0][1] : b[0][1];

    while (i <= a[0][2] && j <= b[0][2])
    {
        if (a[i][0] < b[j][0])
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            k++;
            i++;
        } 
        else if (b[j][0] < a[i][0])
        {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            k++;
            j++;
        }
        else
        {
            if (a[i][1] < b[j][1])
            {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2];
                k++;
                i++;
            }
            else if (a[i][1] > b[j][1])
            {
                c[k][0] = b[j][0];
                c[k][1] = b[j][1];
                c[k][2] = b[j][2];
                k++;
                j++;
            }
            else
            {
                c[k][0] = b[j][0];
                c[k][1] = b[j][1];
                c[k][2] = a[i][2] + b[j][2];
                i++;
                j++;
                k++;
            }

        }
    }
    while (i <= a[0][2])
    {
        c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            k++;
            i++;
    }
    while (j <= b[0][2])
    {
        c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            k++;
            j++;
    }
    c[0][2] = k - 1;

}

void getA(int a[][3])
{
    scanf("%d %d %d", a[0], a[0]+1, a[0]+2);
    for (int i = 1; i <= a[0][2]; i++)
        scanf("%d %d %d", a[i], a[i]+1, a[i]+2);
}

void put(int a[][3])
{
    for (int i = 1; i <= a[0][2]; i++)
        printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
}

int main()
{
    getA(a);
    getA(b);
    add(a, b, c);
    put(c);
}