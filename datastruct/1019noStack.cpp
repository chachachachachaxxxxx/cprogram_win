#include <iostream>
using namespace std;
const int MAXN = 2e5 + 10;

int a[MAXN];

int main()
{
    int N;
    cin >> N;
    int k;
    int t;
    int ptr = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> k;
        if (k == 0)
        {
            cin >> t;
            a[ptr++] = t;
        } else if (k == 1)
        {
            if (ptr > 0)
                ptr--;
        } else
        {
            if (ptr == 0)
                cout << 0 << endl;
            else
            {
                k = a[0];
                for (int i = 1; i < ptr; i++)
                    if (a[i] > k)
                        k = a[i];
                cout << k << endl;
            }
        }
    }
    return 0;
}