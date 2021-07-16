#include <iostream>
#include <string>
using namespace std;

string str;

void solve() {
    int l = str.length();
    char ch = 'a' + l - 1;
    int it1, it2;
    it1 = 0;
    it2 = l - 1;
    while (ch >= 'a') {
        if (str[it1] == ch || str[it2] == ch) {
            if (str[it1] == ch)
                it1++;
            else
                it2--;
            ch--;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int cnum;
    cin >> cnum;
    while (cnum--) {
        cin >> str;
        solve();
    }
}