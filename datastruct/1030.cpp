#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;

typedef struct pair{
    string key;
    string value;
} PAIR;

PAIR map[MAXN];

bool cmp(PAIR a, PAIR b)
{
    if (a.key.compare(b.key) < 0)
        return true;
    return false;
}

int binary_search(string k, int N)
{
    int l = 0, r = N;
    int m = (l + r) / 2;
    int result = 0;
    while ((result = map[m].key.compare(k)) && result != 0 && l <= r)
    {
        if (result < 0)
            l = m + 1;
        else
            r = m - 1;
        m = (l + r) / 2;
    }
    if (l > r)
        return -1;
    return m;
}

int main()
{
    string st;
    string k, v;
    int i = 0;
    int j = 0;
    while (getline(cin, st) && st != "")
    {
        j = 0;
        while (st[j] != ' ')
            j++;
        v = st.substr(0, j);
        k = st.substr(j + 1);
        map[i].key = k;
        map[i].value = v;
        i++;
        // cout << st << endl;
        // cout << k << " " << v << endl;
    }
    sort(map, map + i, cmp);
    while (getline(cin, k))
    {
        j = binary_search(k, i);
        if (j == -1)
            cout << "eh" << endl;
        else
            cout << map[j].value << endl;
    }
}