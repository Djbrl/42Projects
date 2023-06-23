#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    std::string literal;

    if (ac != 2)
        return (0);
    // class is static so need for objects
    ScalarConverter::convert(av[1]);
    return 0;
}