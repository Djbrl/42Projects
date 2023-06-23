#include "Base.hpp"

Base::~Base()
{
}

Base* generate(void)
{
    double n = 1 + (rand() % 3);
    if (n <= 1)
    {
        std::cout << "Class created: A" << std::endl;
        return new A;
    }
    else if (n <= 2)
    {
        std::cout << "Class created: B" << std::endl;
        return new B;
    }
    else
    {
        std::cout << "Class created: C" << std::endl;
        return new C;
    }
}

void identify(Base &p)
{
    if (&p == nullptr)
    {
        std::cout << "(nullref)" << std::endl;
        return ;
    }
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (const std::exception& e)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch (const std::exception& e)
        {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch (const std::exception& e)
            {
              std::cout << "(couldn't dynamic cast)" << std::endl;
            }
        }
    }
}

void identify(Base *p)
{
    if (p == nullptr)
    {
        std::cout << "(nullptr)" << std::endl;
        return ;
    }
    try
    {
        Base *tmp;
        tmp = dynamic_cast<A*>(p);
        if (tmp == nullptr)
        {
            std::cout << "(nullptr)\n";
            return ;
        }
        else
            std::cout << "A" << std::endl;
    }
    catch (const std::exception& e)
    {
        try
        {
            Base *tmp;
            tmp = dynamic_cast<B*>(p);
            if (tmp == nullptr)
            {
                std::cout << "(nullptr)\n";
                return ;
            }
            else
                std::cout << "B" << std::endl;
        }
        catch (const std::exception& e)
        {
            try
            {
                Base *tmp;
                tmp = dynamic_cast<C*>(p);
                if (tmp == nullptr)
                {
                    std::cout << "(nullptr)\n";
                    return ;
                }
                else
                    std::cout << "C" << std::endl;
            }
            catch (const std::exception& e)
            {
              std::cout << "(couldn't dynamic cast)" << std::endl;
            }
        }
    }
}
