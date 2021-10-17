#ifndef GENERLIZEDT_H
#define GENERLIZEDT_H

typedef struct node{
    int tag;
    union date{
        struct node *dlink;
        char data;
    } dd;
    struct node *link;
} NODE;

int depth(NODE *head){
    if (head == NULL) // 如果为空表，返回0
        return 0;

    int MAX = 0;      // 记录该表中元素的深度的最大值
    NODE *p = head;   
    while (p != NULL) // 遍历该表
    {
        if (p->tag == 1)
        {
            if (p->dd.dlink == head) // 如果该表为递归表，则返回-1
                return -1;
            int d = depth(p->dd.dlink); // 记录表中元素的深度

            if (d == -1) // 如果某元素为递归表，则返回-1
                return -1;
            if (d > MAX) 
                MAX = d;
        }
        p = p->link;
    }
    return MAX + 1; 
}

#endif