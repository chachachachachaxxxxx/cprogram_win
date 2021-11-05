#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e4 + 10;

struct segTree{
    int l, r;
    int color;
    int lazy;
}s[MAXN << 4];

void push_up(int rt)
{
    int cl = s[rt << 1].color;
    int cr = s[rt << 1 | 1].color;

    if (cl == -1 || cr == -1)
        s[rt].color = -1;
    else if (cl != cr)
        s[rt].color = -1;
    else
        s[rt].color = cl;
}

void build(int l, int r, int rt)
{
    s[rt].l = l;
    s[rt].r = r;
    s[rt].color = s[rt].lazy = 0;

    if (l == r)
        return;

    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
}

void push_down(int rt)
{
    if (s[rt].lazy != 0)
    {
        s[rt << 1].lazy = s[rt << 1 | 1].lazy = s[rt].lazy;
        s[rt << 1].color = s[rt << 1 | 1].color = s[rt].lazy;
        s[rt].lazy = 0;
    }
}

void update(int L, int R, int c, int rt)
{
    if (s[rt].l >= L && s[rt].r <= R)
    {
        s[rt].color = c;
        s[rt].lazy = c;
        return;
    }
    if (s[rt].l > R || s[rt].r < L)
        return;

    push_down(rt);
    update(L, R, c, rt << 1);
    update(L, R, c, rt << 1 | 1);

    push_up(rt);
}


void query(int L, int R, int rt, int *a)
{
    if (s[rt].color == 0)
        return;
    else if (s[rt].color > 0)
    {
        a[s[rt].color] = 1;
        return;
    }
    push_down(rt);
    query(L, R, rt << 1, a);
    query(L, R, rt << 1 | 1, a);
}


struct segmax{
    int left, right;
} segms[MAXN << 1];

int x[MAXN << 2];

int bsearch(int l, int r, int key)
{
    int ll = l, rr = r;
    int mid = 0;
    while (ll <= rr)
    {
        mid = (ll + rr) >> 1;
        if (x[mid] == key)
            return mid;
        else if (x[mid] > key)
        {
            rr = mid - 1;
        }
        else
            ll = mid + 1;
    }
    return mid;
}


int main()
{
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> segms[i].left >> segms[i].right;
            x[i * 2 + 1] = segms[i].left;
            x[i * 2 + 2] = segms[i].right;
        }

        sort(x + 1, x + 2 * N);

        int m = 0;
        x[m++] = x[1];
        for (int i = 2; i <= 2 * N; i++)
        {
            if (x[i] != x[i-1])
                x[m++] = x[i];
        }

        // for (int i = 0; i < m; i++)
        //     cout << x[i] << " ";
        // cout << endl;

        for (int i = m-1; i >= 1; i--)
        {
            if (x[i] - x[i-1] > 1)
                x[m++] = x[i] - 1;
        }

        sort(x, x + m);

        // for (int i = 0; i < m; i++)
        //     cout << x[i] << " ";
        // cout << endl;

        build(0, m-1, 1);

        int *a = new int[N];
        for (int i = 0; i <= N; i++)
            a[i] = 0;

        for (int i = 0; i < N; i++)
        {
            int l = bsearch(0, m - 1, segms[i].left);
            int r = bsearch(0, m - 1, segms[i].right);

            //cout << l << " " << r << endl;
            update(l, r, i + 1, 1);
        }

        query(0, m - 1, 1, a);

        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            ans += a[i];
        }

        cout << ans << endl;

        delete[] a;
    }
}