#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} NODE;

NODE* insertLinklist(NODE* head, int tar, int val);
NODE* deleteLinklist(NODE* head, int tar);

/* 你的代码将会被嵌入在这个位置 */

int main()
{
    /* 输入及其他处理，细节隐藏不表 */

    NODE* head = createLinklist(/* 创建链表，细节隐藏不表 */);    

    for (/* 若干操作，细节隐藏不表 */)
        if(/* 判断插入还是删除，细节隐藏不表 */)
            head = insertLinklist();
        else
            head = deleteLinklist();

    /* 后续判题，细节隐藏不表 */

    return 0;
}

NODE* insertLinklist(NODE* head, int tar, int val) {
    // TODO
    NODE *p,*ph;
    ph = head;
    p = new NODE;
    p->next = NULL;
    p->data = val;
    if (ph == NULL)
    {
        head = p;
        return head;
    }
    while (ph != NULL)
    {
        if (ph->data == tar)
        {
            p->next = ph->next;
            ph->next = p;
            return head;
        }
        ph = ph->next;
    }
    if (ph == NULL)
    {
        ph = p;
    }
    return head;
}

NODE* deleteLinklist(NODE* head, int tar) {
    if (head == NULL)
        return NULL;
    NODE *ph, *pd;
    ph = head;
    if (ph->data == tar)
    {
        head = ph->next;
        delete ph;
        return head;
    }
    while (ph != NULL)
    {
        pd = ph->next;
        if (pd == NULL)
            break;
        if (pd->data == tar)
        {
            ph->next = pd->next;
            delete pd;
            return head;
        }
        ph = pd;
    }
    return NULL;
}