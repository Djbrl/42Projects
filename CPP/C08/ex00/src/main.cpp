#include "easyfind.hpp"

int main()
{
    std::vector<int> test;
    test.push_back(1);
    test.push_back(22);
    test.push_back(334);

    easyfind(test, 22);

    std::list<char> test2;
    test2.push_back('A');
    test2.push_back('B');
    test2.push_back('C');

    easyfind(test2, static_cast<int>('C'));

    std::deque<int> test3;
    test3.push_back(4);
    test3.push_back(4213);
    test3.push_back(55);

    easyfind(test3, 4);
    
    std::vector<int> test4;
    test4.push_back(4);
    test4.push_back(5);
    test4.push_back(6);

    easyfind(test4, 7);
    
    return 0;
}
