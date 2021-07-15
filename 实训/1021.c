#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void *a, const void *b)
{
    return strcmp((char*)a, (char*)b);
}

int main()
{
    char dic[27];
    char st[100][21];
    int n = 0;
    while (n)
        for (int i = 0; i < 2; i++)
            while (scanf("%s", dic) != EOF)
            {
                int nums = 0;
                while (scanf("%s", st[nums++]) && st[nums - 1][0] != '\n')
                    ;
                for (int i = 1; i < nums; i++)
                {
                    int l = 0;
                    while (st[i][l] != '\0')
                    {
                        if (st[i][l] >= 'a' && st[i][l] <= 'z')
                            for (int k = 0; k < 26; k++)
                            {
                                if (toupper(st[i][l]) == dic[k])
                                {
                                    st[i][l] = k + 'a';
                                }
                            }
                        else
                            for (int k = 0; k < 26; k++)
                                if (st[i][l] == dic[k])
                                {
                                    st[i][l] = k + 'A';
                                }
                        l++;
                    }
                }
                qsort(st + 1, nums - 1, 21, cmp);
                for (int i = 1; i < nums; i++)
                {
                    int l = 0;
                    while (st[i][l] != '\0')
                    {
                        if (st[i][l] >= 'a' && st[i][l] <= 'z')
                            st[i][l] = tolower(dic[st[i][l] - 'a']);
                        else
                            st[i][l] = dic[st[i][l] - 'A'];
                        l++;
                    }
                }
                for (int i = 1; i < nums; i++)
                    printf("%s ", st[i]);
                printf("\n");
            }
    return 0;
}