#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error : wrong number of arguments" << std::endl;
		return 1;
	}
    RPNInterpreter RPN;
    int result = RPN.interpret(av[1]);
    if (result != -1)
    {
        std::cout << result << std::endl;
    }
    return 0;
}