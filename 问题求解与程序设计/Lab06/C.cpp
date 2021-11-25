#include <iostream>
#include <ctime>
using namespace std;
const int MAXN = 110;

long long a, b, anss, t;
long long ans[MAXN];
long long s[MAXN];

long long gcd(long long a, long long b)
{
    if (a > b)
        return gcd(a % b, b);
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

bool dfs(long long k, long long x, long long y)
{
    if (x > y)
    {
        return dfs(k, y, x);
    }
    if (k == 1)
    {
        if (x == 1)
        {        
            for (long long i = 1; i <= t; i++)
            {
                cout << s[i] << " ";
            }
            cout << y << endl;
        }

        // cerr << "wrong" << endl;
        if (x == 1 && y > s[t] && (anss == 0 || y < ans[anss]))
        {
            anss = ++t;
            s[t] = y;
            for (long long i = 1; i <= t; i++)
                ans[i] = s[i];
            t--;
            return true;
        }
        return false;
    }

    bool getans = false;

    long long s1 = s[t] + 1;
    long long s2 = y / x + 1; 
    //cerr << "wrong" << x << " " << y << endl;
    long long imax = k * y / x;
    
    if (ans[anss] != 0 && ans[anss] < imax)
        imax = ans[anss];
    long long im = s1 > s2 ? s1 : s2;
    for (long long i = imax; i >= im; i--)
    {
        // if (ans[anss] != 0 && i >= ans[anss])
        //     break;
        long long yy = y * i;
        long long xx = x * i - y;
        long long gg = gcd(xx, yy);
        xx /= gg;
        yy /= gg;
        s[++t] = i;
        if (dfs(k-1, xx, yy))
            getans = true;
        t--;
        // cerr << "wrong" << endl;
    }
    return getans;
}

int main()
{
    clock_t start, end;

    
    cin >> b >> a;
    start = clock();
    long long gd = gcd(a, b);
    if (gd != 1)
    {
        b /= gd;
        a /= gd;
    }
    if (b == 1)
    {
        cout << a << endl;
        return 0;
    }


    for (long long i = 2; i <=MAXN ;i++)
    {
        t = 0;
        anss = 0;
        // cout << "wrong" << endl;
        if (dfs(i, b, a))
        {
            for (long long i = 1; i <= anss; i++)
                cout << ans[i] << " ";
            cout << endl;

            end = clock();
             cout << "The run time is: " <<(double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

            return 0;
        }
        //cout << i << endl;
    }

}