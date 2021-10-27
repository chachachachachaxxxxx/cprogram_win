#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string st;
    string subst;
    st.reserve
    int index = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> st >> subst;
        index = 0;
        // cout << st.find(subst, index) << endl;
        while ((index = st.find(subst, index)) != -1 && index < (int)st.size())
        {
            for (int i = 0; i < (int)subst.size(); i++)
            {
                st[index + i] = ' ';
            }
            index++;
        }
        cout << "case #" << i << ":" << endl;
        for (int j = 0; j < (int)st.size(); j++)
        {
            if (st[j] != ' ')
                cout << st[j];
        }
        cout << endl;
    }
    // st[0] = ' ';
    // cout << st << endl;
}