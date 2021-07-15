#include <stdio.h>
#include <string.h>
#define N 80
//********** Specification of LongestWord **********
void LongestWord(const char str[],char result[])
/* PreCondition:
   str is a string with length no more than 80
   PostCondition:
   find the first longest word in str, and put it in result.
   changing str is not allowed
*/
{ //TODO: your function definition
    int n = 0;
    int max = 0;
    int i,j;
    i = j = 0;
    char s2[N+1];
    while ((s2[i] = str[j])!= 0)
    {
        if (str[j] == ' ')
        {
            if(n > max)
            {
                max = n;
                s2[i+1] = '\0';
                strcpy(result, s2);
            }
            n = 0;
            i = 0;
        }
        else
        {
            n++;
            i++;
        }
        j++;
    }
    if(n > max)
    {
        s2[i+1] = '\0';
        strcpy(result, s2);
    }
}

/***************************************************************/
int main()
{   char s[N+1],r[N+1];
    gets(s);
//********** LongestWord is called here ************
    LongestWord(s,r);
//**************************************************
    printf("%s\n",r);
    return 0;
}