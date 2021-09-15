#include <iostream>
#include <cstdlib>
#include <ctime>
// #define random(x) rand()%(x)
using namespace std;

int N;

void init(int N, int *a)
{
    int *a = new int[N * N];
    for (int i = 0; i < N * N; i++)
    {
        a[i] = 0;
    }
}

void switch_rand(int *a, int N, int &cnt)
{
    srand((int)time(0));
    int z = rand() % (N * N);
    if (a[z] != 1)
    {
        a[z] = 1;
    } else {
        while (a[z] == 1)
        {
            z = rand() % (N * N);
        }
        a[z] = 1;
    }
    cnt++;
    return;
}

int main()
{
    cin >> N;
    

    delete[] a;
    return 0;
}