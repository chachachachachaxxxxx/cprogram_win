#include <iostream>
using namespace std;
const int MAXN = 21;

int a[MAXN];
int b[MAXN];

int main()
{
    a[0] = 1;
    a[1] = 2;
    a[2] = 4;
    b[0] = b[1] = 0;
    b[2] = 1;
    for (int i = 3; i < MAXN; i++)
    {
        b[i] = a[i - 2] - b[i - 2];
        a[i] = 2 * a[i - 1] -  b[i - 1];
    }
    int k;
    while (cin >> k  && k != -1)
    {
        cout << a[k] << endl;
    }
}