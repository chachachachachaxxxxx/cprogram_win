#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "myHash.h"
using namespace std;

int main(int argv, char *argc[])
{
    ifstream in(argc[1]);
    ofstream out(argc[2]);
    int M;
    cin >> M;
    myHash HT(M);
    string st;
    while (in >> st)
    {
        if (HT.search(st))
            continue;
        HT.insert(st);
    }
    out << M << " " << HT.wordsNum() << " " << HT.loadFactor() << endl;
    int *k;
    k = HT.lenNum();
    for (int i = 0; i < M; i++)
        out << k[i] << endl;
    // out << HT.wordsNum() << endl;
    // out << HT.loadFactor() << endl;
}