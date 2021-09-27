#include <iostream>
#include <cstdlib>
#include <ctime>
#include "percolation_model.h"
// #define random(x) rand()%(x)
using namespace std;

// int N;
// // a实际模型，id、sz是基于模型的并查集
// void init(int N, int *a, int *id, int *sz)
// {
//     int *a = new int[N * N];
//     for (int i = 0; i < N * N; i++)
//     {
//         a[i] = 0;
//         id[i] = i;
//         sz[i] = 0;
//     }
// }

// int find(int p, int *id)
// {
//     while (p != id[p])
//     {
//         p = id[p];
//     }
//     // if (pGSon != -1)
//     // {
//     //     if (sz == sz[p])
//     //     {
//     //         id[pGSon] = p;
//     //         sz[p]
//     //     }
//     // }
//     return p;
// }

// void weigh-QU(int p, int q, int *sz, int *id)
// {
//     int qRoot = find(q, id);
//     int pRoot = find(p, id);
//     if (qRoot == pRoot)
//         return;
//     if (sz[pRoot] == sz[qRoot])
//     {
//         id[q] = pRoot;
//         sz[pRoot]++;
//     } else if (sz[pRoot] < sz[qRoot])
//     {
//         id[p] = qRoot;
//     } else {
//         id[q] = pRoot;
//     }
// }

// void switch_rand(int *a, int N, int &cnt, int *id, int *sz)
// {
//     srand((int)time(0));
//     int z = rand() % (N * N);
//     if (a[z] != 1)
//     {
//         a[z] = 1;
//     } else {
//         while (a[z] == 1)
//         {
//             z = rand() % (N * N);
//         }
//         a[z] = 1;
//     }
//     cnt++;
//     // 并查集合并
//     if (z - 1 >= 0 && )
//     {}
//         return;
// }

// int percolation_if(int N, int *a, int *id)
// {
//     int pRoot, qRoot;
//     for (int i = 0; i < N; i++)
//         for (int j = 0; j < N; j++)
//         {
//             pRoot = find(i, id);
//             qRoot = find(N * (N - 1) + j, id);
//             if (pRoot == qRoot)
//                 return 1;
//         }
//     return 0;
// }

int main()
{
    srand((unsigned)time(0));
    clock_t start, end;
    int N;
    cout << "请输入N：";
    cin >> N;
    cout << "请输入测试次数：";
    int times;
    int ci = 0;
    cin >> times;
    // int k = 0;
    // 并查集问题
    double p_m = 0.0;
    long cnt_sum = 0;
    start = clock();
    int it = 0;
    while(it < times)
    {
        percolation_model pm(N);
        while (!pm.percolation_if())
        {
            pm.switch_rand();
            //printf("\n");
            //k++;
        }
        // p_m = (p_m * ci + (double)pm.cnt_num() / (N * N)) / (ci + 1);
        // ci++;
        cnt_sum += pm.cnt_num();
        it++;
    }
    //cout << cnt_sum << endl;
    p_m = (double)cnt_sum / (long)(N * N * times) * 100;
    end = clock();
    //printf("%d\n", k);
    //printf("%d\n", pm.cnt_num());
    cout << p_m << endl;
    // pm.print_model();
    printf("花费时间：%fs\n", (double)(end-start)/CLOCKS_PER_SEC);
    // pm.path_compression();
    // pm.print_sets();
    return 0;
}