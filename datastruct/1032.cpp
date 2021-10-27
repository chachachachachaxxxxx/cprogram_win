#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 110;

string strs[MAXN];

bool cmp(string a, string b)
{
    int an, bn, ai, bi;
    an = bn = -1;
    ai = bi = 0;
    while (a[ai] != '\0')
    {
        if (a[ai] >= '0' && a[ai] <= '9')
        {
            an = 0;
            while (a[ai] >= '0' && a[ai] <= '9')
            {
                an = an * 10 + a[ai] - '0';
                ai++;
            }
            ai--;
        }
        ai++;
    }
    while (b[bi] != '\0')
    {
        if (b[bi] >= '0' && b[bi] <= '9')
        {
            bn = 0;
            while (b[bi] >= '0' && b[bi] <= '9')
            {
                bn = bn * 10 + b[bi] - '0';
                bi++;
            }
            bi--;
        }
        bi++;
    }
    if (an < bn)
        return true;
    else if (an > bn)
        return false;
    else
    {
        if (a.compare(b) < 0)
            return true;
        else
            return false;
    }
}

int main()
{
    int l = 0;
    string st;
    while (cin >> st)
        strs[l++] = st;
    sort(strs, strs + l, cmp);
    for (int i = 0; i < l; i++)
        cout << strs[i] << " ";
    cout << endl;
    // string st;
    // cin >> st;
    // int a = atoi(st.c_str());
    // cout << a << endl;
}