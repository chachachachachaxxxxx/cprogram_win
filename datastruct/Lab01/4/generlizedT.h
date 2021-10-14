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
    if (head == NULL)
        return 0;

    int MAX = 0;
    NODE *p = head;
    while (p != NULL)
    {
        if (p->tag == 1)
        {
            if (p->dd.dlink == head)
                return -1;
            int d = depth(p->dd.dlink);

            if (d == -1)
                return -1;
            if (d > MAX)
                MAX = d;
        }
        p = p->link;
    }
    return MAX + 1;
}

#endif