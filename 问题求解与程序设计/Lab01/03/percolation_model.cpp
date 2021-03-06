#include <iostream>
#include <ctime>
#include <cstdlib>
#include "percolation_model.h"
#include <random>
using namespace std;

int dx[4] = {-1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

// 改进方式：设起点、会点

percolation_model::percolation_model(int num)
{
    N = num;
    a = new int[N * N + 2];
    cnt = 0;
    id = new int[N * N + 2];
    sz = new int[N * N + 2];
    // locked_num = new int[N * N];
    // locked_length = N * N;
    for (int i = 0; i < N * N + 2; i++)
    {
        a[i] = 0;
        id[i] = i;
        sz[i] = 0;
        // if (i < N * N)
        //     locked_num.push_back(i);
        // locked_num[i] = i;
    }

}

percolation_model::~percolation_model()
{
    delete[] a, id, sz;
}

int percolation_model::find(int p)
{
    while (p != id[p])
        p = id[p];
    return p;
}

void percolation_model::weigh_QU(int p, int q)
{
    int qRoot = find(q);
    int pRoot = find(p);
    if (qRoot == pRoot)
        return;
    if (sz[pRoot] == sz[qRoot])
    {
        id[qRoot] = pRoot;
        sz[pRoot]++;
    } else if (sz[pRoot] < sz[qRoot])
    {
        id[pRoot] = qRoot;
    } else {
        id[qRoot] = pRoot;
    }
}

void percolation_model::switch_rand()
{
    //srand((int)time(0));

    // int num = locked_num.size();
    // if (num == 0)
    //     return;
    // int zi = (rand() * rand()) % num;
    // int z = locked_num[zi];
    // locked_num.erase(locked_num.begin() + zi);

    // int z, xz, yz;
    // xz = rand() % N;
    // yz = rand() % N;
    // z = xz * N + yz;
    // while (a[z] == 1)
    // {
    //     xz = rand() % N;
    //     yz = rand() % N;
    //     z = xz * N + yz;
    // }

    int z;
    z = (rand() * rand()) % (N * N);
    while (a[z] == 1)
    {
        z = (rand() * rand()) % (N * N);
    }

    // random_device rd;
    // mt19937 gen(rd());
    // uniform_int_distribution<int> uniform_dist(0, N * N);
    // int z = uniform_dist(gen) % (N * N);
    // while (a[z] == 1)
    // {
    //     z = uniform_dist(gen) % (N * N);
    // }

    // for (int i = zi; i < locked_length; i++)
    // {
    //     locked_num[i] = locked_num[i + 1];
    // }
    // locked_length--;
    // int z = rand() % (N * N);
    // while (a[z] == 1)
    // {
    //     //srand((int)time(0));
    //     z = rand() % (N * N);
    // }
    a[z] = 1;
    cnt++;
    int col, row;
    row = z / N;
    col = z % N;
    if (row == 0)
        weigh_QU(z, N * N);
    else if (row == N - 1)
        weigh_QU(z, N * N + 1);
    int x, y;
    for (int i = 0; i < 4; i++)
    {
        x = col + dx[i];
        y = row + dy[i];
        if (x >= 0 && x < N && y >= 0 && y < N && a[y * N + x] == 1)
        {
            weigh_QU(z, y * N + x);
        }

    }

        // 并查集合并
        // if (z % N == 0)
        // {
        //     if (z - N >= 0 && id[z - N] == 1)
        //     {
        //         weigh_QU(z - N, z);
        //     }
        //     if (z + N < N * N && id[z + N] == 1)
        //     {
        //         weigh_QU(z + N, z);
        //     }
        //     if (z + 1)
        // }

    return;
}

int percolation_model::percolation_if()
{
    int pRoot, qRoot;
    pRoot = find(N * N);
    qRoot = find(N * N + 1);
    if (pRoot == qRoot)
        return 1;
    // for (int i = 0; i < N; i++)
    // {
    //     if (a[i])
    //     {
    //         for (int j = 0; j < N; j++) // 优化
    //         {
    //             if (a[N * (N - 1) + j])
    //             {
    //                 pRoot = find(i);
    //                 qRoot = find(N * (N - 1) + j);
    //                 //printf("%d %d\n", pRoot, qRoot);
    //                 if (pRoot == qRoot)
    //                 {
    //                     //printf("%d %d %d\n", i, j, pRoot);
    //                     path_print(pRoot);
    //                     return 1;
    //                 }
    //             }
    //         }
    //     }
    // }
    return 0;
}

int percolation_model::cnt_num()
{
    return cnt;
}

void percolation_model::print_model()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", a[i * N + j]);
        printf("\n");
    }
}

void percolation_model::print_sets()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", id[i * N + j]);
        printf("\n");
    }
}

void percolation_model::path_compression()
{
    for (int i = 0; i < N * N; i++)
    {
        int iRoot = find(i);
        id[i] = iRoot;
    }
}

void percolation_model::path_print(int k)
{
    for (int i = 0; i < N * N; i++)
    {
        int root = find(i);
        if (root == k)
            a[i] = 2;
    }
}