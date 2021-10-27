#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    string st;
    for (int j = 0; j < T; j++)
    {
        cin >> st;

        cout << "case #" << j << ":" << endl;
        int k = 1;
        char key = st[0];
        int i = 1;
        for (i = 1; i < (int)st.size(); i++)
        {
            if (st[i] == key && k < 255)
                k++;
            else
            {
                cout << k << key;
                key = st[i];
                k = 1;
            }
        }
        cout << k << key << endl;
    }
}