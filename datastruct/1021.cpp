#include <iostream>
using namespace std;
#include "myStack.h"
const int MAXN = 3e5 + 10;

int a[MAXN * 2];
int stat = 1;
int ptrf, ptrr, len;

int main()
{
    int N, op, n;
    cin >> N;
    ptrr = 0;
    ptrf = -1;
    for (int i = 0; i < N; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> n;
            if (stat == 1)
            {
                a[MAXN + ptrr++] = n;
                cout << a[MAXN + ptrr - 1] << endl;
            } else {
                a[MAXN + ptrf--] = n;
                cout << a[MAXN + ptrf + 1] << endl;
            }
        } else if (op == 2) {
            if (ptrr - ptrf == 1)
                cout << -1 << endl;
            else
            {
                if (stat == 1)
                {
                    ptrr--;
                    if (ptrr - ptrf == 1)
                        cout << -1 << endl;
                    else
                        cout << a[MAXN + ptrr - 1] << endl;
                }
                else
                {
                    ptrf++;
                    if (ptrr - ptrf == 1)
                        cout << -1 << endl;
                    else
                        cout << a[MAXN + ptrf + 1] << endl;
                }
            }
            
        } else if (op == 3) {
            if (stat == 1)
                stat = 2;
            else
                stat = 1;

            if (ptrr - ptrf == 1)
                cout << -1;
            else{
                if (stat == 1)
                {
                    cout << a[MAXN + ptrr - 1] << endl;
                } else {
                    cout << a[MAXN + ptrf + 1] << endl;
                }
            }
        }
    }
    
}