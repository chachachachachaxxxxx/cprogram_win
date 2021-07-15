#include <stdio.h>
#include <stdlib.h>

#define N 10
/********** Specification of transpose **********/



void Transpose(void *a, int n)
/* PreCondition:
a is beginning address of a square matrix, n is the number of rows for the matrix, no more than 80.
PostCondition:
the matrix is transposed
*/
{
    int z;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            z = *((int*)a+i*n+j);
            *((int*)a+i*n+j) = *((int*)a+j*n+i);
            *((int*)a+j*n+i) = z;
        }
    }
}

/*swap(int *x, int *y)
{
    int *z;
    *z = *x;
    *x = *y;
    *y = *z;
}*/

int main()
{   int *a,n,i; scanf("%d",&n);
    a=(int*)malloc(n*n*sizeof(int));
    for (i=0;i<n*n;i++) scanf("%d",a+i);
    Transpose(a,n);
    for (i=0;i<n*n;i++)
    { printf("%d ",a[i]); if ((i+1)%n==0) printf("\n"); }
    free(a);
    return 0;
}