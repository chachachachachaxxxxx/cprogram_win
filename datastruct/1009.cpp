#include <iostream>
using namespace std;
const int MAXN = 1e5 + 10;

int a[MAXN];

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    int tar;
    cin >> tar;
    int flag = 1;
    for (int i = 0; i < N; i++)
    {
        if (a[i] == tar)
        {
            flag = 0;
            cout << i;
            break;
        }
    }
    if (flag)
        cout << -1;
    return 0;
}