#ifndef PERCOLATION_MODEL_H
#define PERCOLATION_MODEL_H
#include <set>

class percolation_model{
private:
    int N;
    int *a;
    int cnt; // 打开板砖个数
    std::set<int> locked_num{};

    int *id;
    int *sz;

public:
    percolation_model(int);
    ~percolation_model();
    // 并查集操作
    int find(int);
    void weigh_QU(int, int);
    
    void switch_rand(); // 随机打开一块板砖
    int percolation_if();  // 判断是否渗漏
    int cnt_num();  // 概率计算
    void print_model(); // 打印模型
    void print_sets();
    void path_compression();
    void path_print(int);
    struct illegal_types{
    };
};
#endif