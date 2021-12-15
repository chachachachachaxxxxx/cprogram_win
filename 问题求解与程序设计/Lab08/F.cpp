#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1e3 + 10;
const double eps = 1e-8;
const double pi = acos(-1);
const double inf = ~0u >> 2;

inline int
sign(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}
struct point{
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y){}
    // struct point operator -(const point &a, const point &b)
    // {
    //     return point(a.x - b.x, a.y - b.y);
    // }
};

//typedef point pointt;
point operator -(point a,point b)
{
    return point(a.x-b.x,a.y-b.y);
}

double dis(point a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

double cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}

double getarea(int n, point *p)
{
    int i;
    double s = 0;
    for (i = 1; i < n - 1; i++)
    {
        s += cross(p[i] - p[0], p[i + 1] - p[0]);
    }
    return s / 2;
}

point intersect(point p1, point p2, point p3,point p4)
{
    point p;
    double a1, b1, a2, b2, c1, c2, d;
    a1 = p1.y - p2.y;
    b1 = p2.x - p1.x;
    c1 = p1.x * p2.y - p2.x * p1.y;
    a2 = p3.y - p4.y;
    b2 = p4.x - p3.x;
    c2 = p3.x * p4.y - p4.x * p3.y;
    d = a1 * b2 - a2 * b1;
    p.x = (-c1 * b2 + c2 * b1) / d;
    p.y = (-a1 * c2 + a2 * c1) / d;
    return p;
}

bool judge(point a, point b, double y)
{
    return sign(a.y - y) * sign(b.y - y) <= 0;
}

point tmp[MAXN];
double cal(double y, point p[], int n)
{
    int i, j;
    int tot = 0;
    point a = point(0, y), b = point(1, y);
    for (i = 1; i < n; i++)
    {
        if (judge(p[i],p[i+1], y))
        {
            tmp[tot++] = intersect(p[i], p[i + 1], a, b);
            break;
        }
    }
    for (j = i + 1; j < n; j++)
    {
        tmp[tot++] = p[j];
        if (judge(p[j], p[j+1], y))
        {
            tmp[tot++] = intersect(p[j], p[j + 1], a, b);
            break;
        }
    }
    double area = getarea(tot, tmp);
    return area;
}   

point p[MAXN];
point q[MAXN];

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int vol, n, m;
        cin >> vol >> n;
        double minz = inf;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i].x >> p[i].y;
            minz = min(minz, p[i].y);
        }
        cin >> m;
        for (int i = 1; i <= m;i++)
        {
            cin >> q[i].x >> q[i].y;
            minz = min(minz, q[i].y);
        }
        // cerr << "wrong" << endl;
        double maxz = min(min(p[1].y, p[n].y), min(q[1].y, q[m].y));
        double lef = minz, rig = maxz, mid;
        // cout << lef << " " << rig << endl;
        while (fabs(rig - lef) > eps)
        {
            mid = (rig + lef) / 2.0;
            double s1 = cal(mid, p, n), s2 = cal(mid, q, m);
            if (sign(s1 + s2 - vol) > 0)
                rig = mid;
            else
                lef = mid;
        }
        printf("%.3f\n", lef);
    }
}