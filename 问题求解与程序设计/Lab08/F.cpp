#include <iostream>
using namespace std;
const double eps = 1e-9;

inline int sign(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}
struct point{
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y){}
    point operator -(point a, point b)
    {
        return point(a.x - b.x, a.y - b.y);
    }
};

double dis(point a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

double cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}

double get

int main()
{

}