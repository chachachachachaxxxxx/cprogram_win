#include <iostream>
using namespace std;
#include "myStack.h"
const int MAXN = 3e5 + 10;

int main()
{
    int N, op, n;
    cin >> N;
    myStack st(N);
    for (int i = 0; i < N; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> n;
            st.push(n);
            cout << st.top() << endl;
        } else if (op == 2) {
            if (!st.empty())
                st.pop();
            if (st.empty())
                cout << -1 << endl;
            else
                cout << st.top() << endl;
        } else {
            st.reverse();
            if (st.empty())
                cout << -1 << endl;
            else
                cout << st.top() << endl;
        }
    }
    
}