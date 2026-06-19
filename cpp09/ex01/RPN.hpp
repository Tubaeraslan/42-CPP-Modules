#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cctype>

class RPN
{
private:
    std::stack<int> _stack;

    bool isOperator(const std::string& token);
    bool isNumber(const std::string& token);
    int calculate(int a, int b, const std::string& op);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int evaluate(const std::string& expression);
};

#endif