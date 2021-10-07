#include <iostream>
#include <string>
#include "myStack.h"
using namespace std;
const int MAXN = 11;

int main()
{
    int T, N;
    string str;
    cin >> T;
    myStack st(MAXN);
    myStack stt(MAXN);
    for (int i = 0; i < T; i++)
    {
        cin >> N >> str;
        for (int j = N - 1; j >= 0; j--)
            stt.push(str[j] - '0');
        for (int i = 0; i < N; i++)
        {
            st.push(i + 1);
            while (!st.empty() && st.top() == stt.top())
            {
                st.pop();
                stt.pop();
            }
        }
        if (stt.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
        st.clear();
        stt.clear();
    }
}