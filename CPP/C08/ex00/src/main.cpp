#include "easyfind.hpp"

int main()
{
    std::vector<int> test;
    test.push_back(1);
    test.push_back(22);
    test.push_back(334);

    easyfind(test, 22);

    std::list<int> test2;
    test2.push_back(4);
    test2.push_back(4213);
    test2.push_back(55);

    easyfind(test2, 55);

    std::deque<int> test3;
    test3.push_back(4);
    test3.push_back(4213);
    test3.push_back(55);

    easyfind(test3, 4);
    return 0;
}
