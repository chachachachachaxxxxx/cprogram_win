#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5;
struct TASK{
    int No;
    int time;
};

TASK task[MAXN];

bool compare_task(const TASK& elem1, const TASK& elem2)
{
    return elem1.time < elem2.time;
}

int main() 
{
    int Tnum;
    scanf("%d\n", &Tnum);
    for (int i = 0; i < Tnum; i++)
    {
        task[i].No = i + 1;
        scanf("%d", &task[i].time);
    }
    sort(task, task + Tnum, compare_task);
    int timesum = 0;
    int T = Tnum;
    for (int i = 0; i < Tnum; i++)
    {
        timesum += T * task[i].time;
        T--;
    }
    printf("%d\n", timesum);
    for (int i = 0; i < Tnum-1; i++)
    {
        printf("%d ", task[i].No);
    }
    printf("%d\n", task[Tnum - 1].No);
    return 0;
}