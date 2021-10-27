#include <iostream>
#include <string>
using namespace std;
int w[6];
int w1[6];

int main()
{
    for (int i = 0; i < 6; i++)
    {
        w[i] = w1[i] = 0;
    }
    string st;
    string st1;
    cin >> st >> st1;
    int max = 0;
    for (int i = 0; i < (int)st.size(); i++)
    {
        if (st[i] == st1[i])
            max++;
        w[st[i] - 'A']++;
        w1[st1[i] - 'A']++;
    }
    int max2 = 0;
    for (int i = 0; i < 6; i++)
    {
        max2 += w[i] < w1[i] ? w[i] : w1[i];
    }
    cout << max << " " << max2 - max << endl;
}