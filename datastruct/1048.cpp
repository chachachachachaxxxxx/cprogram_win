#include <iostream>
using namespace std;
const int MAXN = 4e6+10;
int m, n, c;
int a[MAXN][3];
int b[MAXN][3];
int x[MAXN];

void trans(int a[][3], int b[][3])
{
    for (int i = 0; i < n; i++)
        x[i] = 0;
    for (int i = 0; i < c; i++)
        x[a[i][1] + 1]++;

    for (int i = 1; i < n; i++)
        x[i] += x[i - 1];

    for (int i = 0; i < c; i++)
    {
        int j = x[a[i][1]];
        b[j][0] = a[i][1];
        b[j][1] = a[i][0];
        b[j][2] = a[i][2];
        x[a[i][1]]++;
    }
}

int main()
{
    cin >> m >> n >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> a[i][0];
        cin >> a[i][1];
        cin >> a[i][2];
    }
    trans(a, b);
    for (int i = 0; i < c; i++)
        cout << b[i][0] <<" " <<b[i][1] <<  " " << b[i][2] << endl;
}