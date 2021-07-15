#include<iostream>
int main()
{
    int a,s;
    a = s = 0;
    while (std::cin>>a)
        s += a;
    std::cout << "和是：" << s << std::endl;
    return 0;
}
