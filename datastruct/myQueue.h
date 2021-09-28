#ifndef MYQUEUE_H
#define MYQUEUE_H

class myQueue{
private:
    int *a;
    int rear;
    int front;
    int MAXN;

public:
    myQueue(int);
    ~myQueue();

    void clear();
    // 入队出队
    int enqueue(int);
    int dequeue();
    int find(int);
    // 判空判满
    int size();
    int is_Full();
    int is_Empty();
    // 读取队首或队尾元素
    int front_elem();
    int rear_elem();

    void print();
};

#endif