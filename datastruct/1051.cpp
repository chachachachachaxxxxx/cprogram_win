#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e3 + 10;

void print(int *a, int N)
{
    for (int i = 0; i < N - 1; i++)
        cout << a[i] << " ";
    if (N >= 1)
        cout << a[N - 1];
    cout << endl;
}

int a[MAXN];

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];

    for (int i = 1; i < N; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (a[j] > key && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        print(a, N);
    }
}