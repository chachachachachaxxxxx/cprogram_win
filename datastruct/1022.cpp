#include <iostream>
#include "myStack.h"
#include <string>
#include <stack>
using namespace std;
const int MAXN = 101;

string opt[MAXN];
// +:1
// -:-1
// *:2
// /:3
int main()
{
    myStack op(MAXN);
    stack<double> num;
    string st;
    int nums = 0;
    while (cin >> st)
        opt[nums++] = st;

    double x, y;
    for (int i = nums - 1; i >= 0; i--)
    {
        if (opt[i] == "+")
        {
            x = num.top();
            num.pop();
            y = num.top();
            num.pop();
            num.push(x + y);
        } else if (opt[i] == "-")
        {
            x = num.top();
            num.pop();
            y = num.top();
            num.pop();
            num.push(x - y);
        } else if (opt[i] == "*")
        {
            x = num.top();
            num.pop();
            y = num.top();
            num.pop();
            num.push(x * y);
        } else if (opt[i] == "/")
        {
            x = num.top();
            num.pop();
            y = num.top();
            num.pop();
            num.push(x / y);
        } else {
            num.push(atof(opt[i].c_str()));
        }
    }
    printf("%f\n", num.top());
}
