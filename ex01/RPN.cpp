#include "RPN.hpp"

void RPN::calculate(const std::string& expr)
{
    std::stringstream ss(expr);

    std::string token;

    while (ss >> token)
    {
        if (isdigit(token[0]))
        {
            _stack.push(atoi(token.c_str()));
        }
        else if (token == "+" || token == "-" ||
                 token == "*" || token == "/")
        {
            if (_stack.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return;
            }

            int b = _stack.top();
            _stack.pop();

            int a = _stack.top();
            _stack.pop();

            int result;

            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else
            {
                if (b == 0)
                {
                    std::cerr << "Error" << std::endl;
                    return;
                }

                result = a / b;
            }

            _stack.push(result);
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return;
        }
    }

    if (_stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return;
    }

    std::cout << _stack.top() << std::endl;
}