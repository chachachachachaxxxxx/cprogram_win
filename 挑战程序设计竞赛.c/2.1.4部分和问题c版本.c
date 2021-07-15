#include<stdio.h>
#define MAX_N 20

int n, k;
int a[MAX_N];

int dfs(int i, int sum){
    if (i == n)
        return sum == k;
    if (dfs(i+1,sum))
        return 1;
    if (dfs(i+1,sum+a[i]))
        return 1;
    return 0;
}
int main(){
    int a[MAX_N];
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i = i + 1)
        scanf("%d", &a[i]);
    scanf("%d", &k);
	if (dfs(0,0)==1)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}