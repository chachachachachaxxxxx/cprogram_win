#include <iostream>
using namespace std;
const int MAXN = 1e3 + 10;

double p[MAXN], q[MAXN];
double c[MAXN][MAXN];
double w[MAXN][MAXN];
int N;

void init()
{
    for (int i = 0; i <= N; i++)
    {
        w[i][i] = q[i];
        for (int j = i + 1; j <= N; j++)
        {
            w[i][j] = w[i][j - 1] + p[j] + q[j];
        }
    }
}

void interation()
{
    double mind = 1e5;
    for (int l = 1; l <= N; l++)
    {
        for (int i = 0; i + l <= N; i++)
        {
            mind = 1e5;
            for (int j = i + 1; j <= i + l; j++)
            {
                if (c[i][j-1] + c[j][i + l] < mind)
                {
                    mind = c[i][j - 1] + c[j][i + l];
                }
            }
            c[i][i + l] = mind + w[i][i + l];
            cout << c[i][i + l] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> N;
    double sum = 0.0;
    for (int i = 1; i <= N; i++)
        cin >> p[i];
    for (int i = 0; i <= N; i++)
    {
        cin >> q[i];
        sum += q[i];
    }
    init();
    interation();
    
    printf("%lf\n", c[0][N] + sum);
}