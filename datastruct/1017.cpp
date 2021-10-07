#include <iostream>
#include "myQueue.h"
using namespace std;
const int MAXN = 101;

int terms[MAXN];
int Full(int *a, int len)
{
    for (int i = 0; i < len; i++)
        if (a[i] > 0)
            return 0;
    return 1;
}

int main()
{
    cout << "你好！" << endl;
    int N;
    cin >> N;
    myQueue terms_number[MAXN];
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> terms[i];
        sum += terms[i];
    }
    while (!Full(terms, N))
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <)
        }
    }
}