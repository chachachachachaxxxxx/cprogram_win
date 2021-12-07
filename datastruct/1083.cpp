#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;

int dog[MAXN];
int DOGE[MAXN];

int find(int a)
{
    if (dog[a] == a)
        return a;
    dog[a] = find(dog[a]);
    return dog[a];
}

void Union(int a, int b)
{
    int aroot, broot;
    aroot = find(a);
    broot = find(b);
    if (aroot != broot)
        dog[broot] = aroot;
    return;
}

int main()
{
    int N, n, m;
    cin >> N;
    char op;
    int a, b;
    while (N--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            dog[i] = i;
            DOGE[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> op >> a >> b;
            int aroot = find(a);
            int broot = find(b);
            if (op == 'Q')
            {
                int flag = 0;
                if (aroot == broot)
                    cout << "In the same gang." << endl;
                else
                {
                    if (find(DOGE[a]) == broot)
                    {
                        cout << "In different gangs." << endl;
                        flag = 1;
                    }

                    if (flag == 0)
                        cout << "Not sure yet." << endl;
                }
            }
            else
            {
                if (DOGE[a] == 0)
                    DOGE[a] = b;
                
                if (DOGE[b] == 0)
                    DOGE[b] = a;
                
                
                Union(DOGE[a], broot);
                Union(DOGE[b], aroot);

                DOGE[a] = broot;
                DOGE[b] = aroot;
            }
        }
    }
}