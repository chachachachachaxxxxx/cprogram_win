#include <iostream>
#include <fstream>
using namespace std;

void print(int *a, int len)
{
    for (int i = 0; i < len; i++)
        cout << a[i] << " ";
    cout << endl;
}

void insert_sort(int *a, int len)
{
    int j, key;
    for (int i = 1; i < len; i++)
    {
        j = i - 1;
        key = a[i];
        while (key < a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        print(a, len);
    }
}

void swap(int &a, int &b)
{
    int k = a;
    a = b;
    b = k;
}

void select_sort(int *a, int len)
{
    int mini;
    for (int i = 0; i < len - 1; i++)
    {
        mini = i;
        for (int j = i; j < len; j++)
        {
            if (a[j] < a[mini])
                mini = j;
        }
        if (mini != i)
            swap(a[mini], a[i]);
        print(a, len);
    }
}

void shell_sort(int *a, int len)
{
    int delta, i, j, k, key;
    for (delta = 4; delta; delta /= 4)
    {
        for (i = 0; i < delta; i++)
        {
            for (j = i + delta; j < len; j += delta)
            {
                k = j - delta;
                key = a[j];
                while (k >= 0 && a[k] > key)
                {
                    a[k + delta] = a[k];
                    k -= delta;
                }
                a[k + delta] = key;
                print(a, len);
            }
        }
    }
}

void bubble_sort(int *a, int len)
{
    int j, jmax0;
    int jmax = len - 1;
    int flag = 1;
    while (flag != 0)
    {
        flag = 0;
        jmax0 = jmax;
        for (j = 0; j < jmax0; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j + 1]);
                jmax = j;
                flag = 1;       
            }
        }
        print(a, len);
    }
}

int maxbit(int *a, int len)
{
    int d = 1;
    int p = 10;
    for (int i = 0; i < len; i++)
    {
        while (a[i] >= p)
        {
            p *= 10;
            d++;
        }
    }
    return d;
}

void radix_sort(int *a, int len)
{
    int d = maxbit(a, len);
    int *tmp = new int[len];
    int *count = new int[10];
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++)
    {
        for (j = 0; j < 10; j++)
            count[j] = 0;

        for (j = 0; j < len; j++)
        {
            k = (a[j] / radix) % 10;
            count[k]++;
        }

        for (j = 1; j < 10; j++)
            count[j] += count[j - 1];

        for (j = len - 1; j >= 0; j--)
        {
            k = (a[j] / radix) % 10;
            tmp[count[k] - 1] = a[j];
            count[k]--;
        }

        for (j = 0; j < len; j++)
            a[j] = tmp[j];

        radix *= 10;
        print(a, len);
    }
    delete[] tmp;
    delete[] count;
}


int main(int argv, char *argc[])
{
    ifstream in(argc[1]);

    int N;
    in >> N;
    int *a_insert = new int[N];
    int *a_select = new int[N];
    int *a_shell = new int[N];
    int *a_bubble = new int[N];
    int *a_radix = new int[N];

    for (int i = 0; i < N; i++)
    {
        in >> a_insert[i];
        a_select[i] = a_shell[i] = a_bubble[i] = a_radix[i] = a_insert[i];
    }

    cout << "insert sort:" << endl;
    print(a_insert, N);
    insert_sort(a_insert, N);
    cout << endl;

    cout << "select sort:" << endl;
    print(a_select, N);
    select_sort(a_select, N);
    cout << endl;

    cout << "shell sort:" << endl;
    print(a_shell, N);
    shell_sort(a_shell, N);
    cout << endl;

    cout << "bubble sort:" << endl;
    print(a_bubble, N);
    bubble_sort(a_bubble, N);
    cout << endl;

    cout << "radix sort:" << endl;
    print(a_radix, N);
    radix_sort(a_radix, N);
    cout << endl;

    delete[] a_insert;
    delete[] a_select;
    delete[] a_shell;
    delete[] a_bubble;
    delete[] a_radix;
}