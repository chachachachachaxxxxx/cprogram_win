#include <iostream>
using namespace std;
const int MAXSIZE = 1e5 + 10;

struct array{
    int a[MAXSIZE];
    int length;

    int insert(int x, int pos)
    {
        if (pos < 0 || pos > length)
            return 1;
        else if (length == MAXSIZE)
            return 2;
        for (int i = length; i > pos; i--)
        {
            a[i] = a[i - 1];
        }
        a[pos] = x;
        length++;
        return 0;
    }

    int remove(int pos)
    {
        if (pos < 0 || pos > length)
            return -1;
        int temp = a[pos-1];
        for (int i = pos - 1; i < length - 1; i++)
        {
            a[i] = a[i + 1];
        }
        length--;
        return temp;
    }

    void printa()
    {
        for (int i = 0; i < length; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
} as;

int main()
{
    int num;
    scanf("%d\n", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &as.a[i]);
    }
    as.length = num;
    int op;
    scanf("%d\n", &op);
    for (int i = 0; i < op; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (temp == 1)
        {
            int k, x;
            scanf("%d %d", &k, &x);
            as.insert(x, k);
        }
        else if (temp == 2)
        {
            int k;
            scanf("%d", &k);
            printf("%d\n", as.remove(k));
        }
    }
    as.printa();
    return 0;
}