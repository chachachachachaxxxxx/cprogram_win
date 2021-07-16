#include <iostream>
using namespace std;

struct point {
    int x;
    int y;
};

point A, B;
point F;

void solve() {
    int len;
    len = abs(A.x - B.x) + abs(A.y - B.y);
    if (A.x == B.x && A.x == F.x) {
        if ((A.y < F.y && F.y < B.y) || (A.y > F.y && F.y > B.y))
            len += 2;
    } else if (A.y == B.y && A.y == F.y) {
        if ((A.x < F.x && F.x < B.x) || (A.x > F.x && F.x > B.x))
            len += 2;
    }

    cout << len << endl;
}

int main() {
    int cnum;
    cin >> cnum;
    while (cnum--) {
        cin >> A.x >> A.y >> B.x >> B.y >> F.x >> F.y;
        solve();
    }
    return 0;
}