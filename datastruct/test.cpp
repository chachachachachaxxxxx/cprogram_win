#include <iostream>
using namespace std;

const int MAXSIZE = 100;

int f[MAXSIZE];

int main()
{
    int N;
    cin >> N;
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < N; i++)
    {
        for (int k = 0; k < i; k++)
            f[i] += f[k] * f[i - k - 1];
    }
    for (int i = 0; i < N; i++)
        cout << f[i] << endl;
    return 0;
}