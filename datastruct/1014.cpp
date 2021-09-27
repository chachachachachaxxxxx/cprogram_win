#include <iostream>
using namespace std;
const int MAXN = 101;

int a[MAXN];

int main()
{
    int N, I, K;
    cin >> N >> I >> K;
    I--;
    for (int i = 0; i < N; i++)
    {
        a[i] = i + 1;
    }
    int NN;
    NN = N;
    for (int i = 0; i < N; i++)
    {
        cout << a[(I - 1 + K) % NN] << " ";
        I = (I - 1 + K) % NN ;
        // cout << I << endl
        //      << endl;
        for (int j = I; j < NN; j++)
            a[j] = a[j + 1];
        NN--;
    }
    cout << endl;
}