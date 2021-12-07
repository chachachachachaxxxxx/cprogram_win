#include <iostream>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;
const int MAXN = 1e3 + 10;
const double PI = 3.1415926;

struct point{
    int x, y;
};

point p0;

bool findp0(point a, point b)
{
    if (a.y != b.y)
        return a.y < b.y;
    else
        return a.x < b.x;
}

int cross(point v1, point v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}

double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool rad(point a, point b)
{
    point v1, v2;
    v1.x = a.x - p0.x;
    v1.y = a.y - p0.y;
    v2.x = b.x - p0.x;
    v2.y = b.y - p0.y;
    int s = cross(v1, v2);
    if (s > 0 || (s==0 && dist(a, p0) < dist(b, p0)))
        return true;
    return false;
}

bool isLeftRotate(point a, point b, point c)
{
    point v1, v2;
    v1.x = b.x - a.x;
    v1.y = b.y - a.y;
    v2.x = c.x - b.x;
    v2.y = c.y - b.y;

    // cout << endl;
    int cha = v1.x * v2.y - v1.y * v2.x;
    if (cha > 0)
        return true;
    else
        return false;
}

point ps[MAXN];
stack<point> st;

void GrahamScan(point *ps, int N)
{
    int i = 0;
    st.push(ps[i++]);
    st.push(ps[i++]);
    st.push(ps[i++]);

    point pi, pj, pk;
    while (i <= N)
    {
        if (i < N)
            pk = ps[i++];
        else
        {
            pk = p0;
            i++;
        }
        // cout << pk.x << " " << pk.y << endl;
        pj = st.top();
        st.pop();
        pi = st.top();
        st.pop();

        // cout << endl;
        while (!isLeftRotate(pi, pj, pk) && !st.empty())
        {
            pj = pi;
            pi = st.top();
            st.pop();
        }
        // cout << endl;
        st.push(pi);
        st.push(pj);
        st.push(pk);
    }

}

int N, L;

int main()
{
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        cin >> ps[i].x >> ps[i].y;
    }

    sort(ps, ps + N, findp0);
    p0 = ps[0];
    // cout << endl;
    sort(ps + 1, ps + N, rad);
    // cout << endl;

    // for (int i = 0; i < N; i++)
    // {
    //     cout << ps[i].x << " " << ps[i].y << endl;
    // }

    GrahamScan(ps, N);

    double ans = 0.0;
    ans += PI * 2 * L;

    point p = st.top();
    st.pop();
    point q;
    while (!st.empty())
    {
        q = st.top();
        st.pop();

        ans += sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
        p = q;
    }

    cout << round(ans) << endl;
}