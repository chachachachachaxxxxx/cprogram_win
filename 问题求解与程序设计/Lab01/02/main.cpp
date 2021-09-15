#include <iostream>
#include <ctime>
#include "mysort.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    int length;
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    // int wrong;
    // scanf("%d\n", &wrong);

    // scanf("%d\n", &length);
    // printf("%d\n", length);
    in >> length;
    int *a = new int[length];


    int *a_shell = new int[length];
    int *a_merge = new int[length];
    int *a_quick = new int[length];
    int *a_heap = new int[length];
    int i = 0;
    while(i < length && in >> a[i])
    {
        // printf("%d\n", a[i]);
        a_shell[i] = a_merge[i] = a_quick[i] = a_heap[i] = a[i];
        // printf("%d %d\n", a[i], a_merge[i]);
        i++;
    }
    // printf("你好！\n");
    // int k = 1;
    // printf("%d\n", k);
    clock_t start, end;

    // 插入排序
    start = clock();
    my_insert_sort(a, length);
    end = clock();
    // for (int i = 0; i < length; i++)
    //     out << a[i] << endl;
    printf("插入排序用时：%fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    

    //希尔排序
    // for (int i = 0; i < length; i++)
    //     printf("%d\n", a_shell[i]);
    start = clock();
    my_shell_sort(a_shell, length);
    end = clock();
    for (int i = 0; i < length; i++)
        out << a_shell[i] << endl;
    printf("希尔排序用时：%fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    

    //归并排序
    start = clock();
    my_merge_sort(a_merge, 0, length-1);
    end = clock();
    // for (int i = 0; i < length; i++)
    //     cout << a_merge[i] << endl;
    printf("归并排序用时：%fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    

    //快速排序
    start = clock();
    my_quick_sort(a_quick, 0, length-1);
    end = clock();
    // for (int i = 0; i < length; i++)
    //     cout << a_quick[i] << endl;
    printf("快速排序用时：%fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    //堆排序
    start = clock();
    my_heap_sort(a_heap, length);
    end = clock();
    // for (int i = 0; i < length; i++)
    //     cout << a_heap[i] << endl;
    printf("堆排序用时：%fs\n", (double)(end - start) / CLOCKS_PER_SEC);



    // for (int i = 0; i < length; i++)
    // {
    //     // if (!(a[i] == a_shell[i]))
    //     //     printf("wrong1!\n");
    //     if (!(a_merge[i] == a_shell[i]))
    //         printf("wrong2!\n");
    //     if (!(a_merge[i] == a_quick[i]))
    //         printf("wrong3!\n");
    //     if (!(a_quick[i] == a_heap[i]))
    //         printf("wrong4!\n");
    // }

    in.close();
    out.close();
    delete[] a;
    delete[] a_shell;
    delete[] a_merge;
    delete[] a_quick;
    delete[] a_heap;
}