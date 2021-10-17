#include <iostream>
#include "RBtree.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    srand(unsigned(time(0)));
    ofstream out(argv[1]);
    int N = atoi(argv[2]);
    int M = atoi(argv[3]);
    out << N << " " << M << endl;
    int im = 0;
    while (im < M)
    {
        RBTree rbt;
        int num = 0;
        // NODE *root = rbt.Root();
        for (int i = 0; i < N; i++)
        {
            num = rand() * rand();
            NODE *z = new NODE;
            z->key = num;
            z->isRed = true;
            z->lchild = z->rchild = z->parent = NULL;
            rbt.insert(z);
        }
        int rn = rbt.RedNum();
        int bn = rbt.BlackNum();
        out << depth(rbt.Root()) << " ";
        out << rn * 1.0 / (rn + bn) << endl;
        im++;
    }
}