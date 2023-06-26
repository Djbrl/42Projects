#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stdexcept>
#include <algorithm>

class NotFoundException : public std::exception
{
    public:
        const char* what() const throw();

};

const char* NotFoundException::what() const throw()
{
    return "Exception : Value not found";
}


template<typename T>
void    easyfind(T &container, int n)
{
    typename T::iterator res;
    res = find(container.begin(), container.end(), n);
    try
    {
        if (res == container.end())
        {
            throw NotFoundException();
            return ;
        }
        else
            std::cout << "Value found at index : " << std::distance(container.begin(), res) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}