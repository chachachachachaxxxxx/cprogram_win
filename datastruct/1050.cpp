#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e3 + 10;

int an[MAXN];
int main()
{
    int N;
    cin >> N;
    int a, b, c;
    a = b = c = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> an[i];
    }
    int jk = N - 1;
    int flag = 1;
    while (flag != 0)
    {
        if (jk == 0)
            break;
        flag = 0;
        int jk0 = jk;
        for (int j = 0; j < jk0; j++)
        {
            a++;
            if (an[j] > an[j+1])
            {
                swap(an[j], an[j + 1]);
                b++;
                flag = 1;
                jk = j;
            }
        }
        c++;
        
    }
    cout << a << " " << b << " " << c << endl;
}