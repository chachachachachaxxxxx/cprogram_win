#include <iostream>
#include "mysort.h"

void my_insert_sort(int *a, int num)
{
    for (int i = 1; i < num; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (a[j] > key && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void my_shell_sort(int *a, int num)
{
    
}

void merge(int *a, int start, int mid, int end)
{
    int len = end - start + 1;
    int *b = new int[len];
    int i = start, j = mid + 1, k = 0;
    while (i < mid + 1 && j < end + 1)
    {
        if (a[i] > a[j])
            b[k++] = a[j++];
        else
            b[k++] = a[i++];
    }
    while (i < mid + 1)
        b[k++] = a[i++];
    while (j < end + 1)
        b[k++] = a[j++];
    for (int i = start; i <= end; i++)
    {
        a[i] = b[i - start];
    }
}

void my_merge_sort(int *a, int start, int end)
{
    if (end >= start)
        return;
    int mid = (start + end) / 2;
    my_merge_sort(a, start, mid);
    my_merge_sort(a, mid + 1, end);
    merge(a, start, mid, end);
}

void swap(int *a, int i, int j)
{
    int key = a[i];
    a[i] = a[j];
    a[j] = key;
}

void my_quick_sort(int *a, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    swap(a, left, mid);
    int last = left;
    for (int i = left + 1; i <= right; i++)
    {
        if (a[i] < a[left])
            swap(a, ++last, i);
    }
    swap(a, last, left);
    my_quick_sort(a, left, mid);
    my_quick_sort(a, mid + 1, right);
}

void my_heap_sort(int *a, int num)
{
    
}