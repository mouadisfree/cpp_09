#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN
{
    private:
        std::stack<int> _stack;

    public:
        void calculate(const std::string& expr);
};

#endif