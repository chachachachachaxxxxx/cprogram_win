#include<iostream>
int main()
{
    std::cout << "请输入两个数字：" << std::endl;
    int a, b;
    std::cin >> a >> b;
    ++a;
    while (a<b){
        std::cout << a << std::endl;
        ++a;
    }
    return 0;
}