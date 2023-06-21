#include "Base.hpp"

int main()
{
    Base *base = generate();
    Base *test = nullptr;

    identify(base);  
    identify(*base);
    identify(test);
    identify(*test);
    return 0;
}