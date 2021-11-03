#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N = 0;

void print(int *a, int len)
{
    for (int i = 0; i < len; i++)
        cout << a[i] << " ";
    cout << endl;
}

void quick_sort(int *a, int left, int right)
{
    if (left >= right)
        return;
    
    int i = 0;

    int low = left, up = right;
    swap(a[left], a[(left + right) / 2]);

    printf("%d:a[%d](%d)<->a[%d](%d)\n", i++, left, a[left], (left + right) / 2, a[(left + right) / 2]);

    int key = a[low];
    while (low < up)
    {
        while (a[up] >= key && up > low)
            up--;
        if (up > low)
        {
            a[low++] = a[up];
            printf("%d:a[%d](%d)->a[%d]\n", i++, up, a[up], low - 1);
        }
            
        while (a[low] < key && low < up)
            low++;
        if (up > low)
        {
            a[up--] = a[low];
            printf("%d:a[%d](%d)->a[%d]\n", i++, low, a[low], up + 1);
        }   
    }
    a[low] = key;
    printf("%d:key(%d)->a[%d]\n", i++, key, low);
    printf("\n");
    print(a, N);
    printf("\n");

    quick_sort(a, left, low - 1);
    quick_sort(a, low + 1, right);
}

int main(int argv, char *argc[])
{
    ifstream in(argc[1]);
    in >> N;
    int *a = new int[N];
    for (int i = 0; i < N; i++)
        in >> a[i];
    print(a, N);
    printf("\n");
    quick_sort(a, 0, N - 1);

}