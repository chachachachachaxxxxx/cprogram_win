#include <iostream>
#define MAX_N 20
int a[MAX_N];
int n, k;

using namespace std;

bool dfs(int i, int sum){
    if (i == n)
        return sum == k;
    if (dfs(i+1, sum))
        return true;
    if (dfs(i+1, sum+a[i]))
        return true;
    return false;
}

void solve(){
    if (dfs(0,0))
        printf("Yes\n");
    else
        printf("No\n");
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;
    solve();
    return 0;
}