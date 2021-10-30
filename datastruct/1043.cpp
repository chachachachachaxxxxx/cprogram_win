#include <iostream>
#include <cstring>
using namespace std;
const int ASIZE = 256;
const int XSIZE = 1e5 + 10;

void preBmBc(char *x, int m, int bmBc[])
{
    int i;
    for (i = 0; i < ASIZE; ++i)
        bmBc[i] = m;
    for (i = 0; i < m - 1; ++i)
        bmBc[(int)x[i]] = m - i - 1;
}

void suffixes(char *x, int m, int *suff)
{
    suff[m - 1] = m;
    int i, q;
    for (i = m - 2; i >= 0; --i)
    {
        q = i;
        while (q >= 0 && x[q] == x[m - 1 - i + q])
            q--;
        suff[i] = i - q;
    }
}

void preBmGs(char *x, int m, int bmGs[])
{
    int i, j, suff[XSIZE];
    suffixes(x, m, suff);
    for (i = 0; i < m; ++i)
        bmGs[i] = m;

    j = 0;
    for (i = m - 1; i >= 0; i--)
        if (suff[i] == i + 1)
            for (; j < m - 1 - i; j++)
                if (bmGs[j] == m)
                    bmGs[j] = m - 1 - i;

    for (i = 0; i <= m - 2; i++)
        bmGs[m - 1 - suff[i]] = m - 1 - i;
}

void BM(char *x, int m, char *y, int n)
{
    int i, j, bmGs[XSIZE], bmBc[ASIZE];
    preBmGs(x, m, bmGs);
    preBmBc(x, m, bmBc);

    j = 0;
    int flag = 0;
    while (j <= n - m)
    {
        for (i = m - 1; i >= 0 && x[i] == y[i + j]; --i)
            ;
        if (i < 0)
        {
            cout << j << endl;
            flag = 1;
            break;
        }
        else
        {
            int x1 = bmGs[i];
            int x2 = bmBc[(int)y[i + j]] - m + 1 + i;
            j += x1 > x2 ? x1 : x2;
        }
    }
    if (flag == 0)
        cout << -1 << endl;
    for (int i = 0; i < 26; i++)
        cout << bmBc['a' + i] << " ";
    cout << endl;
}

char x[XSIZE];
char y[XSIZE];

int main()
{
    cin >> y >> x;
    BM(x, strlen(x), y, strlen(y));
}