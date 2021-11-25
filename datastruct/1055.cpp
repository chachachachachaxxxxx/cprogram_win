#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 10;
int a[MAXN];

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
    sort(a, a + N);
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    cout << endl;
}