#include <iostream>
#include <fstream>
using namespace std;

bool is_word(char a)
{
    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
        return true;
    return false;
}

char toLower(char a)
{
    if (a >= 'A' && a <= 'Z')
        a -= 'A' - 'a';
    return a;
}

int main()
{
    ifstream in("A Tale of Two Cities - Charles Dickens.txt");
    ofstream out("text2.txt");
    char a;
    while (in.get(a))
    {
        if (is_word(a))
        {
            //a = toLower(a);
            out << a;
            while (in.get(a) && is_word(a))
            {
                //a = toLower(a);
                out << a;
            }
            out << endl;
        }
    }
}