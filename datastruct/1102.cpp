#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int MAXN = 101;

int in[MAXN];
vector<int> vec[MAXN];
int N;

bool topo_sort()
{
    stack<int> st;
    for (int i = 1; i <= N; i++)
    {
        if (in[i] == 0)
        {
            st.push(i);
        }
    }

    while (!st.empty())
    {
        int k = st.top();
        st.pop();
        for (auto x: vec[k])
        {
            in[x]--;
            if (in[x] == 0)
            {
                st.push(x);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (in[i] > 0)
        {
            // cout << i << " " << in[i] << endl;
            return false;
        }
            
    }
    return true;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int s;
        cin >> s;
        in[i] = s;
        for (int j = 0; j < s; j++)
        {
            int a;
            cin >> a;
            vec[a].push_back(i);
        }
    }

    if (topo_sort())
        cout << 1 << endl;
    else
        cout << 0 << endl;
}