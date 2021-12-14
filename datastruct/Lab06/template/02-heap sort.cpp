#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

/**
 * 给定一组未排序的结点(类型为整数)序列, 建一个大顶堆
 * 同时计算建堆时的交换次数
 * 数组下标从0开始
 * @param arr   	[大小为arrSize的数组]
 * @param arrSize	[数组大小]
 *
 * @return          [建堆过程中的交换次数]
 */



int buildHeap(int *arr, int arrSize) {
    /** TODO **/
    int cnt = 0;

    for (int i = (arrSize - 2) / 2; i >= 0; i--)
    {
        int j, t, i0;
        t = arr[i];
        i0 = i;
        while ((j = 2 * i0 + 1) < arrSize)
        {
            if (j + 1 < arrSize && arr[j] < arr[j + 1])
                j++;
            if (arr[j] > t)
            {
                arr[i0] = arr[j];
                i0 = j;
                cnt++;
            }
            else
                break;
        }
        arr[i0] = t;
    }

    // for (int i = 0; i < arrSize; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    return cnt;
}

/**
 * 给定一个大小为arrSize的未排序的堆, 输出堆排序后的序列
 * 同时计算堆排序过程中的交换次数
 * @param arr   	[大小为arrSize的堆]
 * @param arrSize	[堆的大小]
 *
 * @return          [堆排序过程中的交换次数]
 */
int heapSort(int *arr, int arrSize) {
    /** TODO **/

    int t, j, i0;
    int cnt = 0;
    for (int i = arrSize - 1; i > 0; i--)
    {
        t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        cnt++;

        t = arr[0];
        i0 = 0;
        while ((j = 2 * i0 + 1) < i)
        {
            if (j + 1 < i && arr[j] < arr[j+1])
                j++;
            if (arr[j] > t)
            {
                arr[i0] = arr[j];
                i0 = j;
                cnt++;
            }
            else
                break;
        }
        arr[i0] = t;
    }

    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc((n)*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int buildSwapCnt = buildHeap(arr, n);
    int sortSwapCnt = heapSort(arr, n);
    printf("%d %d\n", buildSwapCnt, sortSwapCnt);
    //输出排好序的序列

    return 0;
}
