#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

bool contains(list<int> li, int value)
{list<int>::iterator it;
    for (it = li.begin(); it != li.end(); it++)
    {
        if (*it == value)
            return true;
    }
    return false;
}

int main()
{
    list<int> li;
    int k;
    cin >> k;
    while (k != -1)
    {
        li.push_back(k);
        cin >> k;
    }
    //li.print();
    cin >> k;
    while (k != -1)
    {
        if (contains(li, k))
            li.remove(k);
        else
            cout << -1 << endl;
        // if (li.remove(k) == -1)
        //     cout << -1 << endl;
        cin >> k;
        //li.print();
    }
    list<int>::iterator it;
    for (it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}