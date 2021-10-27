#include <iostream>
using namespace std;
const int MAXN = 1e4 + 10;

char st1[MAXN];
char st2[MAXN];

int main()
{
    cin >> st1 >> st2;
    int flag = 0;
    int ri = -1;
    for (int i = 0; st1[i] != '\0'; i++)
    {
        if (st1[i] == st2[0])
        {
            int j = 0;
            for (j = 1; st2[j] != '\0'; j++)
                if (st1[i + j] != st2[j])
                    break;
            if (st2[j] == '\0')
            {
                flag = 1;
                ri = i;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    cout << ri << endl;
}