#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
const int Y = 1e9 + 7;

string strs[MAXN];
int P, L;

int myhash(string st)
{
    int s = 0;
    for (int i = 0; i < (int)st.length(); i++)
        s = (s * 128 + (int)st[i]) % Y;
    return s;
}

typedef struct picture{
    int hashL;
    int hashR;
    int index;
    int sortIndex;
} PIC;

bool cmp(PIC a, PIC b)
{
    return a.sortIndex < b.sortIndex;
}

PIC pics[1010];

int main()
{
    cin >> P >> L;
    getchar();
    for (int i = 0; i < P; i++)
    {
        pics[i].index = i * L;
        for (int j = 0; j < L; j++)
        {
            getline(cin, strs[i * L + j]);
        }
        pics[i].hashL = myhash(strs[i * L]);
        pics[i].hashR = myhash(strs[i * L + L - 1]);

        // cout << endl;

        // if (i == 0)
        //     pics[i].sortIndex = 0;

        // if (i >= 1)
        // {
        //     if (pics[i - 1].hashR == pics[i].hashL)
        //     {
        //         pics[i].sortIndex = pics[i - 1].sortIndex + 1;
        //     }
        //     else if (pics[i-1].hashL == pics[i].hashR)
        //     {
        //         pics[i].sortIndex = pics[i - 1].sortIndex - 1;
        //     }
        // }
    }

    pics[0].sortIndex = 0;
    int hashL = pics[0].hashL;
    int hashR = pics[0].hashR;
    for (int i = 1; i < P; i++)
    {
        if (pics[i].hashR == hashL)
        {
            pics[i].sortIndex = pics[i - 1].sortIndex - 1;
            hashL = pics[i].hashL;
        }
        else if (pics[i].hashL == hashR)
        {
            pics[i].sortIndex = pics[i - 1].sortIndex + 1;
            hashR = pics[i].hashR;
        }
        else
        {
            pics[i].sortIndex = -100;
            hashL = pics[i].hashL;
            hashR = pics[i].hashR;
        }
    }

    sort(pics, pics + P, cmp);

    for (int l = pics[0].index, j = 0; j < L; j++, l++)
        {
            cout << strs[l] << endl;
        }

    for (int i = 1; i < P; i++)
    {
        for (int l = pics[i].index + 1, j = 1; j < L; j++, l++)
        {
            cout << strs[l] << endl;
        }
    }
}