#include <iostream>
#include <cstring>
#include "phonebook.hpp"

void phonebook::add(this)
{
    std::cin >> this->contactlist[0];
}

int main(int ac, char **av)
{
    int i = 1;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        while (i < ac)
        {
            for (int j = 0; j < strlen(av[i]); j++)
                std::cout << (char)toupper(av[i][j]);
            std::cout << " ";
            i++;
        }
        std::cout << "\b\n";
    }
    return 0;
}