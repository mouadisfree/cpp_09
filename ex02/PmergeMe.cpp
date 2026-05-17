#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av)
{
    for (int i = 1; av[i]; i++)
    {
        int n = std::atoi(av[i]);

        if (n < 0)
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }

        _vec.push_back(n);
        _deq.push_back(n);
    }
}

PmergeMe::~PmergeMe()
{
}

size_t PmergeMe::getSize() const
{
    return _vec.size();
}

void PmergeMe::printBefore()
{
    std::cout << "Before: ";

    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";

    std::cout << std::endl;
}

void PmergeMe::printAfter()
{
    std::cout << "After: ";

    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";

    std::cout << std::endl;
}

void PmergeMe::sortVector()
{
    mergeInsertVector(_vec);
}

void PmergeMe::sortDeque()
{
    mergeInsertDeque(_deq);
}

void PmergeMe::mergeInsertVector(std::vector<int>& v)
{
    if (v.size() <= 1)
        return;

    size_t mid = v.size() / 2;

    std::vector<int> left(v.begin(), v.begin() + mid);
    std::vector<int> right(v.begin() + mid, v.end());

    mergeInsertVector(left);
    mergeInsertVector(right);

    v.clear();

    size_t i = 0;
    size_t j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            v.push_back(left[i]);
            i++;
        }
        else
        {
            v.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size())
    {
        v.push_back(left[i]);
        i++;
    }

    while (j < right.size())
    {
        v.push_back(right[j]);
        j++;
    }
}

void PmergeMe::mergeInsertDeque(std::deque<int>& d)
{
    if (d.size() <= 1)
        return;

    size_t mid = d.size() / 2;

    std::deque<int> left(d.begin(), d.begin() + mid);
    std::deque<int> right(d.begin() + mid, d.end());

    mergeInsertDeque(left);
    mergeInsertDeque(right);

    d.clear();

    size_t i = 0;
    size_t j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            d.push_back(left[i]);
            i++;
        }
        else
        {
            d.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size())
    {
        d.push_back(left[i]);
        i++;
    }

    while (j < right.size())
    {
        d.push_back(right[j]);
        j++;
    }
}