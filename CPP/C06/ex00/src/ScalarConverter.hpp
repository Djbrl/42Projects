#include <iostream>
#include <string>

class ScalarConverter
{
    private:
        const std::string _value;
        ScalarConverter();
    public:
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator=(const ScalarConverter &src);
        static void convert(std::string literalVar);
};

