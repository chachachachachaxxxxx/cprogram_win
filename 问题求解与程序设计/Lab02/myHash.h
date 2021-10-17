#ifndef MYHASH_H
#define MYHASH_H
#include <list>
#include <string>
using namespace std;

class myHash{
private:
    list<string> *base;
    int *list_len;
    int length;
    int num;
public:
    myHash(int);
    ~myHash();
    int index(string);
    bool search(string);
    void insert(string);
    void remove(string);

    double loadFactor();
    int wordsNum();
    int *lenNum();
    int search2(string);
};

myHash::myHash(int N)
{
    length = N;
    base = new list<string>[length];
    list_len = new int[length];
    for (int i = 0; i < length; i++)
    {
        list_len[i] = 0;
    }
    num = 0;
}

myHash::~myHash()
{
    delete[] base;
    delete[] list_len;
}

int myHash::index(string st)
{
    int id = 0;
    for (int i = 0; i < (int)st.size(); i++)
    {
        id = (id * 128 + st[i]) % length;
    }
    return id;
}

bool myHash::search(string st)
{
    int ind = index(st);
    list<string>::iterator it;
    for (it = base[ind].begin(); it != base[ind].end(); it++)
    {
        if (*it == st)
            return true;
    }
    return false;
}

void myHash::insert(string st) // 和search会有冗余操作
{
    if (this->search(st)) 
        return;
    int ind = index(st);
    base[ind].push_back(st);
    num++;
    list_len[ind]++;
}

void myHash::remove(string st)
{
    int ind = index(st);
    base[ind].remove(st);
    num--;
    list_len[ind]--;
}

int myHash::wordsNum()
{
    return num;
}

double myHash::loadFactor()
{
    return num * 1.0 / length;
}

int* myHash::lenNum()
{
    return list_len;
}

int myHash::search2(string st)
{
    int ind = index(st);
    list<string>::iterator it;
    int i = 0;
    for (it = base[ind].begin(); it != base[ind].end(); it++, i++)
    {
        if (*it == st)
            return i + 1;
    }
    return i;
}

#endif