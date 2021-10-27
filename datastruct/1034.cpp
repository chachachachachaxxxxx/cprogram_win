#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N, len, l, r;

    cin >> N;
    string st;
    string ou;
    for (int i = 0; i < N; i++)
    {
        cin >> len >> st;
        l = 0;
        r = len - 1;
        ou = "";
        while (l <= r)
        {
            if (st[l] < st[r])
                ou += st[l++];
            else if (st[l] > st[r])
                ou += st[r--];
            else
            {
                int lt = l + 1;
                int rt = r - 1;
                while (lt <= rt)
                {
                    if (st[lt] != st[rt])
                    {
                        if (st[lt] < st[rt])
                            ou += st[l++];
                        else
                            ou += st[r--];
                        break;
                    }
                    lt++;
                    rt--;
                }
                if (lt > rt)
                    ou += st[l++];
            }
        }
        cout << "case #" << i << ":" << endl;
        cout << ou << endl;
    }
}