#include <iostream>
#include <string>

class ScalarConverter
{
    private:
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator=(const ScalarConverter &src);
        static void convert(std::string literalVar);
};

