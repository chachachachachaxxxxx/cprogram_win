#include <iostream>
#include <string>
using namespace std;
const int MAXN = 1e5 + 10;
int turn[MAXN];
string peo[MAXN];

int main()
{
    int N, op;
    cin >> N >> op;
    for (int i = 0; i < N; i++)
    {
        cin >> turn[i] >> peo[i];
    }
    int tar = 0;
    int tur, step;
    int temp = 1;
    for (int i = 0; i < op; i++)
    {
        cin >> tur >> step;
        if (tur == turn[tar])
            temp = -1;
        else
            temp = 1;
        tar += step * temp;
        tar = (N + tar) % N;
    }
    cout << peo[tar] << endl;
}
