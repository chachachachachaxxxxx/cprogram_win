#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class dlink { // 双向链表
    dlink *pre;
    dlink *suc;

public:
    void insert(dlink *);
};

void dlink::insert(dlink* p) {
    p->suc = suc;
    p->pre = this;
    suc->pre = p;
    suc = p;
}



void f(string& s1, string& s2, string& s3) { // error: temporary objects used error
    const char *cs = (s1 + s2).c_str();
    cout << cs;
    if (strlen(cs = (s2+s3).c_str()) < 8 && cs[0] == 'a') { // temporary objects used right, used in one expression

    }
}




class Point{
public:
    Point(int x, int y);
};

class Shape {
public:
    void MoveTo(Point);
};

void f(Shape& s, int x, int y) {
    s.MoveTo(Point(x, y));
}


int main() {
    return 0;
}