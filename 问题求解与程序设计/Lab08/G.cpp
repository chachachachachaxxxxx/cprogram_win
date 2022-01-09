#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 2e3 + 10;
const double eps = 1e-8;
const double pi = acos(-1);

inline int sign(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}

struct point {
    double x, y, z;
};

double xycross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}

bool xyjudge(point p1, point p2, point p3, point p4)
{
    point v1, v2, v3, v4;
    v1.x = p3.x - p1.x;
    v1.y = p3.y - p1.y;
    v2.x = p4.x - p1.x;
    v2.y = p4.y - p1.y;
    v3.x = p3.x - p2.x;
    v3.y = p3.y - p2.y;
    v4.x = p4.x - p2.x;
    v4.y = p4.y - p2.y;

    v1.z = v2.z = v3.z = v4.z = 0;
    if (sign(xycross(v1, v2) * xycross(v3, v4)) <= 0 && sign(xycross(v1, v3) * xycross(v2, v4)) <= 0)
        return true;
    return false;
}

point intersect(point p1, point p2, point p3, point p4)
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
    if (d == 0)
    {
        p.x = p1.x;
        p.y = p1.y;
        p.z = 0;
        return p;
    }
    p.x = (-c1 * b2 + c2 * b1) / d;
    p.y = (-a1 * c2 + a2 * c1) / d;

    p.z = 0;
    return p;
}

int zjudge(point p1, point p2, point p3, point p4)
{
    if (!xyjudge(p1, p2, p3, p4))
        return 0;

    point pz = intersect(p1, p2, p3, p4);
    // cout << pz.x << pz.y << pz.z << endl;
    double z1 = p1.z + (p2.z - p1.z) * sqrt(pow(pz.x - p1.x, 2) + pow(pz.y - p1.y, 2)) / sqrt(pow(p2.x - p1.x, 2)+ pow(p2.y - p1.y, 2));
    double z3 = p3.z + (p4.z - p3.z) * sqrt(pow(pz.x - p3.x, 2)+ pow(pz.y - p3.y, 2)) / sqrt(pow(p4.x - p3.x, 2)+ pow(p4.y - p3.y, 2));

    // cout << z1 << " " << z3 << endl;
    if (sign(z1 - z3) == 1)
        return 1;
    return -1;
}

point vec[MAXN][2];
vector<int> vect;
int gx[MAXN][MAXN];
vector<int> more[MAXN];

bool judge(vector<int> vect, int N)
{
    if (N == 2)
        return true;

    bool used[MAXN];

    while (N > 2)
    {
        for (int i = 0; i < N; i++)
            used[i] = false;

        int k = 0;
        used[0] = true;
        bool flag = true;
        while (flag)
        {
            
            flag = false;
            for (int i = 0; i < N; i++)
            {
                // cout << vect[i] << " " <<  vect[k] << " " << gx[vect[i]][vect[k]] << endl;
                //  int *pos = find(&more[i][1], &more[i][more[i][0]], k);
                // cout << find(more[vect[i]].begin(), more[vect[i]].end(), vect[k]) << endl;
                // auto it = find(more[vect[i]].begin(), more[vect[i]].end(), vect[k]);
                // if (it != more[vect[i]].end())
                //     cout << *it << endl;
                // cout << more[vect[i]].size() << endl;
                if (i != k && find(more[vect[i]].begin(), more[vect[i]].end(), vect[k]) != more[vect[i]].end())
                {
                    // cout << endl;
                    if (used[i])
                        return false;
                    else
                    {
                        used[i] = true;
                        k = i;
                        flag = true;
                        // cout << endl;
                        break;
                    }
                    
                }
            }
        }
        swap(vect[N - 1], vect[k]);
        N--;
    }

    // swap(vect[N - 1], vect[k]);
    // cout << endl;
    return true;
}

int test[] = {1, 2, 6};

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i][0].x >> vec[i][0].y >> vec[i][0].z;
        cin >> vec[i][1].x >> vec[i][1].y >> vec[i][1].z;
        vect.push_back(i);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            // gx[i][j] = zjudge(vec[i][0], vec[i][1], vec[j][0], vec[j][1]);
            int zj = zjudge(vec[i][0], vec[i][1], vec[j][0], vec[j][1]);
            if (zj == 1)
            {
                more[i].push_back(j);
            } else if (zj == -1)
            {
                more[j].push_back(i);
            }
            // gx[j][i] = gx[i][j] * (-1);
        }
    }
    // cout << gx[0][1] << gx[1][2] << gx[2][0];
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << vec[test[i]][0].x <<" " <<  vec[test[i]][0].y << " " <<vec[test[i]][0].z << " " <<vec[test[i]][1].x <<" " << vec[test[i]][1].y << " " << vec[test[i]][1].z<< endl;
    // }

        bool ans = judge(vect, N);
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
        // printf();
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         if (i == j)
    //             continue;
    //         if (gx[i][j] == -2)
    //         {
    //             gx[i][j] = zjudge(vec[i][0], vec[i][1], vec[j][0], vec[j][1]);
    //             gx[j][i] = -gx[i][j];
    //         }
    //         if (gx[i][j] == 1)
    //         {
    //             for (int k = 0; k < N; k++)
    //             {
    //                 if (k == i || k == j)
    //                     continue;
                    
    //                 if (gx[j][k] == -2)
    //                 {
    //                     gx[j][k] = zjudge(vec[j][0], vec[j][1], vec[k][0], vec[k][1]);
    //                     gx[k][j] = -gx[j][k];
    //                 }

    //                 if (gx[j][k] == -2)
    //                 {
    //                     gx[j][k] = zjudge(vec[j][0], vec[j][1], vec[k][0], vec[k][1]);
    //                     gx[k][j] = -gx[j][k];
    //                 }
    //             }
    //         }
    //     }
    // }
}