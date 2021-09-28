#include <iostream>
#include "myStack.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    myStack st(N);
    int k;
    for (int i = 0; i < N; i++)
    {
        cin >> k;
        if (k == 0)
        {
            cin >> k;
            st.push(k);
        } else if (k == 1)
        {
            if (!st.empty())
                st.pop();
        } else
        {
            if (st.empty())
                cout << 0 << endl;
            else
            {
                cout << st.find_max() << endl;
            }
        }
    }
    return 0;
}