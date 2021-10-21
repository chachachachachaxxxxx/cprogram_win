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

    int mini = 0;
    for (int i = 0; i < N - 1; i++)
    {
        mini = i;
        for (int j = i + 1; j < N; j++)
        {
            if (a[j] < a[mini])
                mini = j;
        }
        swap(a[i], a[mini]);
        print(a, N);
    }
}