#include <iostream>
#include <map>
#include <string>
using namespace std;
const double INF = 1e8;

int N, M;
map<string, int> has;
double G[40][40];

int main()
{
    int ni = 1;
    while (cin >> N)
    {
        if (N == 0)
            break;

        has.clear();
        for (int i = 1; i <= N; i++)
        {
            string a;
            cin >> a;
            has[a] = i;
        }
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
        {
            G[i][j] = 0;
            if (i == j)
                G[i][j] = 1;
        }

                cin >> M;
        for (int i = 0; i < M; i++)
        {
            string a, b;
            double r;
            cin >> a >> r >> b;
            G[has[a]][has[b]] = r;
        }

        bool flag = false;
        for (int k = 1; k <= N; k++)
        {
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= N; j++)
                {
                    if (G[i][k] * G[k][j] > G[i][j])
                    {
                        G[i][j] = G[i][k] * G[k][j];
                    }
                    if (i == j && G[i][j] > 1)
                    {
                        flag = true;
                        break;
                    }

                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
        

        cout << "Case " << ni << ": ";
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        ni++;
    }
}