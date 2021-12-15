#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000
#define inf 0x7fffffff

typedef struct huffnode {
    char data; // 值
    struct huffnode * leftChild; // 左子树
    struct huffnode * rightChild; // 右子树
    /* 其他成员变量，细节隐藏不表 */
} HUFFNODE;

char decode[MAXN];
int 
void init(HUFFNODE *head, int n)
{
    if (head->leftChild == NULL && head->rightChild == NULL)
    {
        decode[n] = head->data;
        return;
    }
    if (head == NULL)
        return;
    init(head->leftChild, n * 3 + 1);
    init(head->rightChild, n * 3 + 2);
}

void decipherHuffmanCoding(HUFFNODE* head, char cipher[])
{
    init(head, 0);
    int d = 0;
    for (int i = 0; i < strlen(cipher); i++)
    {
        if (cipher[i] == '1')
        {
            d = d * 3 + 2;
        } else {
            d = d * 3 + 1;
        }

        if (decode[d] != 0)
        {
            printf("%c", decode[d]);
            d = 0;
        }
    }
    printf("\n");
}