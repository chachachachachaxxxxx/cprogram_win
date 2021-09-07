#include <iostream>
#include <set>
using namespace std;

const int MAXN = 2e5 + 10;
int n, k;
int a[MAXN];
int b[MAXN];
int cnt[MAXN];

int max(const int arr[],int n)
{
	int count;
	const int*p=arr;
	for(count=1;count<n;count++)
	{
		if(*p<arr[count])
			p=&arr[count];
	}
	return p-arr;
}

void solve() {
    for (int i = 0; i < n; i++)
    {
        b[i] = 0;
    }
    int s = 0;
    for (int i = 1; i <= n; i++) {  
        if (cnt[i] > k)
            cnt[i] = k;
        s += cnt[i];
        //cout << i << ":" << cnt[i] << endl;
    }
    int ave = s / k;
    /*for (int i = 1; i <= k; i++)
    {
        pa[i] = ave;
    }
    for (int i = 0; i < n; i++)
    {
        
    }

    for (int i = 0; i < n; i++)
    {

    }*/

    //cout << ave << endl;
    int paint = 1;
    while (paint <= k) {
        int tk = 1;
        set<int> st;
        while (tk <= ave) {
            int ik = max(cnt, n + 1);
            if (st.count(ik) == 1) {
                int t = cnt[ik];
                int ik1 = ik;
                cnt[ik] = 0;
                ik = max(cnt, n + 1);
                cnt[ik1] = t;
            }
            st.insert(ik);
            cnt[ik]--;
            for (int i = 0; i < n; i++) {
                if (a[i] == ik && b[i] == 0) {
                    b[i] = paint;
                    tk++;
                    break;
                }
            }
        }
        paint++;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
    printf("\n");
}

int main () {
    int T;
    scanf("%d\n", &T);
    while (T--) {
        for (int i = 0; i < MAXN; i++)
            cnt[i] = 0;
        scanf("%d %d\n", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            cnt[a[i]]++;
        }
        solve();
    }
}