#include <iostream>
#include <string>
#include <stack>
using namespace std;
const int MAXN = 1000;

int isp(char c)
{
    switch(c)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
        case '$':
            return -1;
        default:
            return -2;
    }
}

char myStack[MAXN];

int mid_to_pos(const char *s, char *to)
{
    int top = 0;
    myStack[top] = '$';
    int is, ito;
    is = ito = 0;
    while (s[is] != '\0')
    {
        //cout << s[is] << endl;
        if ( (s[is] >= '0' && s[is] <= '9') || s[is] == '.')
        {
            while ((s[is] >= '0' && s[is] <= '9') || s[is] == '.')
            {
                to[ito++] = s[is++];
            }
            to[ito++] = ' ';
            // cout << s[is] << endl;
        }
        else if (s[is] == ' ')
        {
            is++;
            continue;
        }
        else
        {
            switch(s[is])
            {
                case '+':
                case '-':
                    if (is == 0 || s[is - 1] == '(')
                    {
                        to[ito++] = '0';
                        to[ito++] = ' ';
                    }
                case '*':
                case '/':
                    while (isp(s[is]) <= isp(myStack[top]))
                    {
                        to[ito++] = myStack[top--];
                        to[ito++] = ' ';
                    }
                    myStack[++top] = s[is++];
                    break;
                case '(':
                    myStack[++top] = s[is++];
                    break;
                case ')':
                    while (myStack[top] != '(')
                    {
                        to[ito++] = myStack[top--];
                        to[ito++] = ' ';
                    }
                    top--;
                    is++;
                    break;
                default:
                    return -1;
            }
        }
    }
    while (top > 0)
    {
        to[ito++] = myStack[top--];
        to[ito++] = ' ';
    }
    to[ito] = '\0';
    return 0;
}

int main()
{
    string st1;
    getline(cin, st1);
    char s[MAXN];
    mid_to_pos(st1.c_str(), s);
    //cout << s << endl;

    stack<double> num;

    double x, y;
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '+')
        {
            x = num.top();
            num.pop();
            y = num.top();
            num.pop();
            num.push(x + y);
        } else if (s[i] == '-')
        {
            x = num.top();
            num.pop();
            y = num.top();
            num.pop();
            num.push(y - x);
        } else if (s[i] == '*')
        {
            x = num.top();
            num.pop();
            y = num.top();
            num.pop();
            num.push(x * y);
        } else if (s[i] == '/')
        {
            x = num.top();
            num.pop();
            y = num.top();
            num.pop();
            num.push(y / x);
        } else if (s[i] != ' '){
            char s_num[10];
            int is = 0;
            while (s[i] != ' ')
            {
                s_num[is++] = s[i++];
            }
            s_num[is] = '\0';
            //cout << atof(s_num) << endl;
            num.push(atof(s_num));
        }
        i++;
    }
    // printf("%f\n", num.top());
    cout << num.top() << endl;
}
