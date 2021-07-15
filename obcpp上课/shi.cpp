#include <iostream>
#include <string>
struct A{
    A() {
        std::cout << "Initialize" << std::endl;
    }
    ~A() {
        std::cout << "Clean up" << std::endl;
    }
};

std::ostream &operator<<(std::ostream &os, const char* a){
    os << "Initialize\n"
       << a << "Clean up\n";
    return os;
}   

int main() {
    operator<<(std::cout, "Hello world!\n");
} // nishizhendesb