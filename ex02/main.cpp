#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe p(av);

    p.printBefore();

    clock_t startVec = clock();
    p.sortVector();
    clock_t endVec = clock();

    clock_t startDeq = clock();
    p.sortDeque();
    clock_t endDeq = clock();

    p.printAfter();

    std::cout << "Time to process a range of "
              << p.getSize()
              << " elements with std::vector : "
              << (endVec - startVec) * 1000000.0 / CLOCKS_PER_SEC
              << " us"
              << std::endl;

    std::cout << "Time to process a range of "
              << p.getSize()
              << " elements with std::deque : "
              << (endDeq - startDeq) * 1000000.0 / CLOCKS_PER_SEC
              << " us"
              << std::endl;

    return 0;
}