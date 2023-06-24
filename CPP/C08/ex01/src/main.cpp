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

Tester::~Tester()
{
}

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

// class Awesome
// {
//     public:
//         Awesome( void ) : _n( 42 ) { return; }
//         int get( void ) const { return this->_n; }
//     private:
//         int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

// template< typename T >
// void print( T const &x)
// {
//     std::cout << x << std::endl; return; 
// }

// int main()
// {
//     int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
//     Awesome tab2[5];
//     iter( tab, 5, print );
//     iter( tab2, 5, print );
//     return 0;
// }

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
