#include <iostream>
#include "generlizedT.h"
using namespace std;

int main()
{
    NODE *Eh = NULL;
    NODE *h1 = new NODE;
    h1->tag = 0;
    h1->dd.data = 'c';
    h1->link = NULL;
    NODE *Rh = new NODE;
    Rh->tag = 0;
    Rh->dd.data = 'c';
    Rh->link = new NODE;
    Rh->link->tag = 1;
    Rh->link->dd.dlink = Rh;
    Rh->link->link = NULL;

    cout << depth(Eh) << endl;
    cout << depth(h1) << endl;
    cout << depth(Rh) << endl;
}