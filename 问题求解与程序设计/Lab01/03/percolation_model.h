#ifndef PERCOLATION_MODEL_H
#define PERCOLATION_MODEL_H

class percolation_model{
private:
    int N;
    int *a;
    int cnt; // 打开板砖个数

    int *id;
    int *sz;

public:
    percolation_model(int);
    // 并查集操作
    int find(int p);
    void weight_QU(int p, int q);
    
    void switch_rand(); // 随机打开一块板砖
    void percolation_if();  // 判断是否渗漏 
};
#endif