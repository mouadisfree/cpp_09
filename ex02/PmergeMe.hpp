#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

class PmergeMe
{
private:
    std::vector<int> _vec;
    std::deque<int> _deq;

    void mergeInsertVector(std::vector<int>& v);
    void mergeInsertDeque(std::deque<int>& d);

public:
    PmergeMe(char **av);
    ~PmergeMe();

    void sortVector();
    void sortDeque();

    void printBefore();
    void printAfter();

    size_t getSize() const;
};

#endif