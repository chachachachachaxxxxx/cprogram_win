#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int d;
        cin >> d;
        q.push(d);
    }
    int sum = 0;
    while (q.size() > 1)
    {
        int a, b;
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        q.push(a + b);
        sum += a + b;
    }
    cout << sum << endl;
}