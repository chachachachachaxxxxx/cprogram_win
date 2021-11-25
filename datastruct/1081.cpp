#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 3e4 + 100;
int people[MAXN];
int temp[MAXN];
int sums[MAXN];

int find(int a)
{
    if (people[a] == a)
        return a;
    people[a] = find(people[a]);
    return people[a];
}

void Union(int a, int b)
{
    int aroot, broot;
    aroot = find(a);
    broot = find(b);
    if (aroot != broot)
        people[broot] = aroot;
    return;
}

int main()
{
    int M, N, tn;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        people[i] = i;
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> tn;
        for (int j = 0; j < tn; j++)
            cin >> temp[j];
        for (int j = 1; j < tn; j++)
        {
            Union(temp[0], temp[j]);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        
    }
}