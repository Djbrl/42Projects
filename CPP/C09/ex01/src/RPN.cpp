#include "RPN.hpp"

RPNInterpreter::RPNInterpreter()
{}

RPNInterpreter::~RPNInterpreter()
{}

RPNInterpreter::RPNInterpreter(const RPNInterpreter &src)
{ (void)src; }

RPNInterpreter& RPNInterpreter::operator=(const RPNInterpreter &src)
{ (void)src; return *this; }

int RPNInterpreter::interpret(const std::string &expr)
{
    std::istringstream exprStream(expr);
    std::string token;

    //PROCESS ALL TOKENS
    while (exprStream >> token)
    {
        //IF TOKEN IS DIGIT, ADD TO STACK
        if (isdigit(token[0]))
            operands.push(std::stoi(token));
        //IF TOKEN IS OPERATOR, DO THE OPERATION
        else if (!handleOperator(operands, token))
            return -1;
    }
    if (operands.size() != 1)
    {
        std::cout << "Error : more than one operand left" << std::endl;
        return -1;
    }
    return operands.top();
}

bool RPNInterpreter::handleOperator(std::stack<int> &operands, const std::string &token)
{
    if (operands.size() < 2)
    {
        std::cout << "Error : not enough operands " << std::endl;
        return false;
    }

    //TAKE 2 DIGITS FROM STACK
    int secondOperand = operands.top();
    operands.pop();
    int firstOperand = operands.top();
    operands.pop();
    
    int result;
    //APPLY TOKEN TO OPERANDS
    if (token == "+")
        result = firstOperand + secondOperand;
    else if (token == "-")
        result = firstOperand - secondOperand;
    else if (token == "*")
        result = firstOperand * secondOperand;
    else if (token == "/") {
        if (secondOperand == 0)
        {
            std::cout << "Error : division by 0" << std::endl;
            return false;
        }
        result = firstOperand / secondOperand;
    } else {
        std::cout << "Error : invalid operator (+/*- only)" << std::endl;
        return false;
    }
    //PLACE RESULT 
    operands.push(result);
    return true;
}
