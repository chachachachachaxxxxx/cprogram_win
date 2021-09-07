#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 60;
char s[MAXN];
int ch[MAXN];

void solve() {
    for (int i = 0; i < MAXN; i++) {
        ch[i] = 0;
    }
    for (int i = 0; i < strlen(s); i++) {
        ch[s[i] - 'a']++;
    }
    int s = 0;
    for (int i = 0; i < 26; i++) {
        if (ch[i] >= 2)
            s += 2;
        else 
            s += ch[i];
    }

    printf("%d\n", s / 2);
}

int main () {
    int T;
    scanf("%d\n", &T);
    while (T--) {
        scanf("%s\n", s);
        solve();
    }
}