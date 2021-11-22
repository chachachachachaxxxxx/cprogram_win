#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 1e5 + 10;
bool not_prime[MAXN];
int haveIn[MAXN];

void prime()
{
    not_prime[1] = 1;
    for (int i = 2; i * i <= MAXN;i++)
    {
        if(!not_prime[i])
        {
            for (int j = i * i; j <= MAXN; j+=i)
                not_prime[j] = 1;
        }
    }
}

int bfs(int src, int des)
{
    queue<int> st;
    st.push(src);
    haveIn[src] = 1;

    int s, s1;
    int rest1, rest2;
    int weight;
    while (!st.empty())
    {
        s = st.front();
        st.pop();
        // cout << s << endl;
        if (s == des)
            return haveIn[s];

        weight = 1000;
        
        for (; weight > 0; weight /= 10)
        {
            rest1 = s / (weight * 10);
            rest2 = s % weight;
            for (int i = 0; i < 10; i++)
            {
                s1 = rest1 * weight * 10 + weight * i + rest2;
                if (s1 >= 1000 && !not_prime[s1] && !haveIn[s1])
                {
                    st.push(s1);
                    haveIn[s1] = haveIn[s] + 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    prime();
    // cout << not_prime[8017] << endl;
    int N, a, b, ans;
    cin >> N;
    while (N--)
    {
        for (int i = 0; i < MAXN; i++)
            haveIn[i] = 0;
        cin >> a >> b;
        ans = bfs(a, b);
        cout << ans - 1 << endl;
    }
}