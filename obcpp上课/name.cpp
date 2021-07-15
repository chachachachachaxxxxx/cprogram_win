#include <iostream>
#include <string>
using namespace std;

class Name { const char *s;
};

class Table {
    Name *p;
    size_t sz;
public:
    Table(int s = 10) : p{new Name[sz = s]} {} //by default
    ~Table() { delete[] p; }

    //copy constructor
    Table(const Table &);
    //assignment operator
    Table& operator= (const Table & );

    Name *lookup(const char *);
    bool insert(Name *);
};

void uninitialized_copy_n(Name* from, size_t, Name* to) {
    
}

Table& Table::operator= (const Table& t) {
    if (this != &t) {
        delete[] p;
        p = new Name[sz = t.sz];
        uninitialized_copy_n(t.p, sz, p);
    }
    return *this;
}


int main() {
    Table t1;
    Table vt[10];
    string s1{"abc"};
    string s2 = "abcdefg";
    cout << sizeof(s1) << endl
         << sizeof(s2) << endl
         << sizeof(int) << endl;

    return 0;
}

//