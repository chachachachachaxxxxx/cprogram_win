#include <stdio.h>
#include <stdlib.h>
#define N 10000

typedef struct {
    long long num;
    char name[15];
    int score[3];
} STUDENT;


/********** Specification of Input **********/
STUDENT* Input(int n)
/* PreCondition:
     the length of student namelist
   PostCondition:
     an pointer pointed to the array that store information of n students
*/
{ //TODO: your function definition
    STUDENT *a;
    a = (STUDENT*)malloc(n*sizeof(STUDENT));
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %s %d %d %d", &a[i].num, &a[i].name, &a[i].score[0], &a[i].score[1], &a[i].score[2]);
    }
    return a;
}
int cmp(STUDENT *a, STUDENT *b)
{
    long long anum, bnum, asum, bsum;
    anum = a->num;
    bnum = b->num;
    asum = a->score[0] + a->score[1] + a->score[2];
    bsum = b->score[0] + b->score[1] + b->score[2];
    if (asum != bsum)
    {
        if (asum > bsum)
            return -1;
        else return 1;
    }
    else
    {
        if (anum < bnum)
            return -1;
        else return 1;
    }
}

/********** Specification of Sort **********/
void Sort(STUDENT *ps, int n)
/* PreCondition:
       ps points to a Student array with n positive integers
   PostCondition:
       Array pointed by ps is sorted based on their mean scores in descending order.
       If two students have identical mean scores, the order is based on student
       numbers in ascending order.
*/
{ //TODO: your function definition
    qsort(ps, n, sizeof(STUDENT), cmp);
}

int main() {
    STUDENT* a = NULL;
    int i, n;
    scanf("%d\n", &n);

    a = Input(n);
    Sort(a, n);

    for (i = 0; i < n; i++)
        printf("%lld %s %d %d %d\n", a[i].num, a[i].name,
               a[i].score[0], a[i].score[1], a[i].score[2]);
    return 0;
}