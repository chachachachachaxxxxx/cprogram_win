// 8 12 10 14 9 13 11 15
// 4 6 5 7
// 00 10 01 11
// 前半为左 后半为右
// 4 2  
// 8 10 12 14
// 3 2
// 4 5 6 7
// 2 2
// 2 3
// 3 * 2 * 2

// 4 7
// 9 11 13 15
// 4 5 6 7
// 3
// 2 3
// 1
// 11
// 2 *2 + 1 * 2 + 1
// 3 4
// 5 7
// 2 2

#include <iostream>
using namespace std;

int solve(int D, int I)
{
    if (D == 1)
        return 1;
    // if (D == 2)
    // {
    //     if (I % 2 == 1)
    //         return 2;
    //     else
    //         return 3;
    // }

    int prior = 1;
    for (int i = 0; i < D - 1; i++)
        prior *= 2;
    I %= prior;
    if (I == 0)
        I += prior;

    if (I <= prior / 2)
        return 2 * solve(D - 1, I);
    else
        return 2 * solve(D - 1, I) + 1;
}

int main()
{
    int N, D, I, A;
    cin >> N;
    while (N--)
    {
        cin >> D >> I;
        A = solve(D, I);
        cout << A << endl;
    }
}