#include <iostream>
using namespace std;
const int MAXN = 101;

int maze[MAXN * MAXN];

class DSU{
private:
    int *a;
    int *sz;
    int length;

public:
    DSU(int N){
        a = new int[N * N];
        sz = new int[N * N];
        for (int i = 0; i < N * N; i++)
        {
            a[i] = i;
            sz[i] = 0;
        }
    }
    ~DSU(){
        delete[] a;
        delete[] sz;
    }

    int find(int id)
    {
        while (id != a[id])
        {
            id = a[id];
        }
        return id;
    }

    void weigh_QU(int p, int q)
    {
        int pRoot = find(p);
        int qRoot = find(q);
        if (qRoot == pRoot)
            return;
        if (sz[pRoot] == sz[qRoot])
        {
            a[qRoot] = pRoot;
            sz[pRoot]++;
        } else if (sz[pRoot] > sz[qRoot])
        {
            a[qRoot] = pRoot;
        } else {
            a[pRoot] = qRoot;
        }
    }

    bool united(int p, int q)
    {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot)
            return true;
        return false;
    }
};

int dx[3] = {-1, 0, 1};
int dy[3] = {-1, 0, 1};

//int a[MAXN * MAXN];
int flag[MAXN * MAXN];

bool islegal(int x, int y, int n)
{
    if (x < n && x >= 0 && y >= 0 && y < n && maze[x * n + y] == 0 && flag[x * n + y] == 0)
        return true;
    return false;
}

void dfs(int x1, int y1, int n)
{
    for (int dx = -1; dx < 2; dx++)
        for (int dy = -1; dy < 2; dy++)
        {
            if (islegal(dx + x1, dy + y1, n) )
            {
                flag[(dx + x1) * n + dy + y1] = 1;
                //a[(dx + x1) * n + dy + y1] = 1;
                dfs(dx + x1, dy + y1, n);
            }
        }
}

int main()
{
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    char c;
    int i = 0;
    while (cin >> c)
    {
        if (c == '0')
            maze[i++] = 0;
        if (c == '1')
            maze[i++] = 1;
    }
    flag[x1 * n + y1] = 1;
    dfs(x1, y1, n);
    if (flag[x2 * n + y2] == 1)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}