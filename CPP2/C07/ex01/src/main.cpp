#include <iostream>
#include "iter.hpp"

//============================TEMPLATE DEFINITION============================

template<typename T>
void incrementer(T &src)
{ src += 40; }

template<typename T>
void iter(T *addr, int size, void (*func)(T &))
{
    for (int i = 0; i < size; i++) {
        (*func)(addr[i]);
    }
}
//============================TEMPLATE DEFINITION============================

//============================TESTER CLASS DEFINITION============================

Tester::Tester(const int &n) : _a(n) 
{}

int Tester::getAttr() const
{
    return _a;
}

Tester &Tester::operator+=(const Tester &src)
{
    _a += src.getAttr();
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const Tester &rhs)
{
    return stream << rhs.getAttr();
}
//============================TESTER CLASS DEFINITION============================

//MAIN
int main() {
    std::string strArr[3] = { "hi", "im", "gosu" };
    Tester objArr[3] = { Tester(3), Tester(2), Tester(1) };
    int intArr[3] = { 3, 2, 1 };

    std::cout << "==INT ARRAY TEST==" << std::endl;
    iter(intArr, 3, incrementer);
    for (int i = 0; i < 3; i++)
        std::cout << intArr[i] << std::endl;
    std::cout << "==STR ARRAY TEST==" << std::endl;
    iter(strArr, 3, incrementer);
    for (int i = 0; i < 3; i++)
        std::cout << strArr[i] << std::endl;
    std::cout << "==OBJ ARRAY TEST==" << std::endl;
    iter(objArr, 3, incrementer);
    for (int i = 0; i < 3; i++)
        std::cout << objArr[i] << std::endl;
    return 0;
}
