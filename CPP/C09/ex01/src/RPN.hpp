#include <iostream>
#include <stack>
#include <sstream>

class RPNInterpreter
{
    private:
        std::stack<int> operands;
        bool            handleOperator(std::stack<int> &operands, const std::string &token);
                        RPNInterpreter(const RPNInterpreter &src);
                        RPNInterpreter &operator=(const RPNInterpreter &src);
    public:
                        RPNInterpreter();
                        ~RPNInterpreter();
        int             interpret(const std::string &expr);
};
