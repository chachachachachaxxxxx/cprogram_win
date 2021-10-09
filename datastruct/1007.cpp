#include <iostream>
#include "myList.h"
using namespace std;

int main()
{
    myList li;
    int k;
    cin >> k;
    while (k != -1)
    {
        li.add(k);
        cin >> k;
    }
    //li.print();
    cin >> k;
    while (k != -1)
    {
        if (li.remove(k) == -1)
            cout << -1 << endl;
        cin >> k;
        //li.print();
    }
    li.print();
    return 0;
}