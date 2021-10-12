#include <iostream>
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
    }
}

char myStack[MAXN];

int mid_to_pos(char s[], char to[])
{
    int top = 0;
    int is, ito;
    is = ito = 0;
    while (s[is] != '\0')
    {
        if ((s[is] >= '0' && s[is] <= '9') || s[is] == '.')
        {
            while ((s[is] >= '0' && s[is] <= '9') || s[is] == '.')
            {
                to[ito++] = s[is++];
            }
            to[ito++] = ' ';
            is--;
        }
        else
        {
            switch(s[is])
            {
                case '+':
                case '-':
                case '*':
                case '/':
                    while (isp(s[is]) <= isp(myStack[top]))
                        
            }
        }
    }
}

int main()
{

}