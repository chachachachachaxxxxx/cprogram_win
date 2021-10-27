#include <iostream>
#include <string>
using namespace std;
const int MAXN = 100;

int main()
{
    char *st1, *st2;
    st1 = new char[MAXN];
    st2 = new char[MAXN];
    scanf("%s %s", st1, st2);
    char *st;
    
    st = new char[MAXN * 2];
    int i1, i2;
    i1 = i2 = 0;
    int i = 0;
    while (st1[i1] != '\0' && st2[i2] != '\0')
    {
        if (i & 1)
            st[i++] = st2[i2++];
        else
            st[i++] = st1[i1++];
    }
    while (st1[i1] != '\0')
        st[i++] = st1[i1++];
    while (st2[i2] != '\0')
        st[i++] = st2[i2++];
    st[i] = '\0';
    printf("%s\n", st);
    delete[] st1;
    delete[] st2;
    delete[] st;
}