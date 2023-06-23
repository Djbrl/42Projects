#include <iostream>
#include <string>

template<typename T>
void incrementer(T &src);

template<typename T>
void iter(T *addr, int size, void (*func)(T &));

class Tester 
{
    private:
        int _a;
        Tester();
    public:
        ~Tester();
        Tester(const int &n);
        int getAttr() const;
        Tester &operator+=(const Tester &src);
};
