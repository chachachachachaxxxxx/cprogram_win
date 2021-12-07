#include <iostream>
#include <map>
#include <string>
using namespace std;

const int MAXN = 1e5 + 10;

map<string, int> peopleToNo;
int people[MAXN];
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
    int N,F;
    cin >> N;
    string a, b;
    while (N--)
    {
        peopleToNo.erase(peopleToNo.begin(), peopleToNo.end());
        
        cin >> F;
        for (int i = 1; i <= 2 * F; i++)
        {
            sums[i] = 1;
        }
        int No = 1;
        for (int i = 0; i < F; i++)
        {
            cin >> a;
            if (peopleToNo.find(a) == peopleToNo.end())
            {
                peopleToNo[a] = No;
                people[No] = No;
                No++;
            }
            cin >> b;
            if (peopleToNo.find(b) == peopleToNo.end())
            {
                peopleToNo[b] = No;
                people[No] = No;
                No++;
            }
            if (find(peopleToNo[a]) != find(peopleToNo[b]))
                sums[find(peopleToNo[a])] += sums[find(peopleToNo[b])];
            Union(peopleToNo[a], peopleToNo[b]);
            
            cout << sums[find(peopleToNo[a])] << endl;
        }
    }
}