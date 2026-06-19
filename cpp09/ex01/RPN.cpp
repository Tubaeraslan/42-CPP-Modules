#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token)
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token)
{
    if (token.size() != 1)
        return false;
    return std::isdigit(token[0]);
}

int RPN::calculate(int a, int b, const std::string& op)
{
    if (op == "+")
        return a + b;
    if (op == "-")
        return a - b;
    if (op == "*")
        return a * b;
    if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Error");
        return a / b;
    }
    throw std::runtime_error("Error");
}

int RPN::evaluate(const std::string& expression)
{
    std::stack<int> empty;
    _stack.swap(empty);

    std::stringstream ss(expression);
    std::string token;

    while (ss >> token)
    {
        if (isNumber(token))
        {
            _stack.push(token[0] - '0');
        }
        else if (isOperator(token))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");

            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();

            _stack.push(calculate(a, b, token));
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.top();
}