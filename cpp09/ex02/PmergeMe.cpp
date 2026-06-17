#include "PmergeMe.hpp"


PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::process(char **argv)
{
    parseInput(argv);
    printBefore();

    double vectorTime = sortVector();
    double dequeTime = sortDeque();

    printAfter();

    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::vector : " << vectorTime << " us\n";

    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque : " << dequeTime << " us\n";
}

void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); i++)
    {
        std::cout << _vector[i];
        if (i + 1 != _vector.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); i++)
    {
        std::cout << _vector[i];
        if (i + 1 != _vector.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

double PmergeMe::sortVector()
{
    clock_t start = clock();
    fordJohnsonVector(_vector);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC * 1000000;
}

double PmergeMe::sortDeque()
{
    clock_t start = clock();
    fordJohnsonDeque(_deque);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::parseInput(char **argv)
{
    for (int i = 1; argv[i]; i++)
    {
        std::string s(argv[i]);

        if (!isValidNumber(s))
        {
            std::cerr << "Error\n";
            exit(1);
        }

        long n = std::atol(s.c_str());
        _vector.push_back(n);
        _deque.push_back(n);
    }
}

bool PmergeMe::isValidNumber(const std::string& str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.size(); i++)
        if (!std::isdigit(str[i]))
            return false;

    long n = std::atol(str.c_str());
    if (n < 0 || n > INT_MAX)
        return false;

    return true;
}

void PmergeMe::binaryInsertVector(std::vector<int>& vec, int value)
{
    size_t l = 0, r = vec.size();

    while (l < r)
    {
        size_t mid = (l + r) / 2;
        if (value < vec[mid])
            r = mid;
        else
            l = mid + 1;
    }
    vec.insert(vec.begin() + l, value);
}

void PmergeMe::binaryInsertDeque(std::deque<int>& deq, int value)
{
    size_t l = 0, r = deq.size();

    while (l < r)
    {
        size_t mid = (l + r) / 2;
        if (value < deq[mid])
            r = mid;
        else
            l = mid + 1;
    }
    deq.insert(deq.begin() + l, value);
}

std::vector<size_t> PmergeMe::generateJacobsthalOrder(size_t size)
{
    std::vector<size_t> order;
    std::vector<bool> used(size, false);

    size_t j0 = 0;
    size_t j1 = 1;

    while (j1 < size)
    {
        order.push_back(j1);
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }

    for (size_t i = 0; i < size; i++)
        if (std::find(order.begin(), order.end(), i) == order.end())
            order.push_back(i);

    return order;
}

void PmergeMe::fordJohnsonVector(std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return;

    std::vector<int> bigs;
    std::vector<int> smalls;

    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        if (vec[i] < vec[i + 1])
        {
            smalls.push_back(vec[i]);
            bigs.push_back(vec[i + 1]);
        }
        else
        {
            smalls.push_back(vec[i + 1]);
            bigs.push_back(vec[i]);
        }
    }

    if (vec.size() % 2 == 1)
        bigs.push_back(vec.back());

    fordJohnsonVector(bigs);
    vec = bigs;

    std::vector<size_t> order = generateJacobsthalOrder(smalls.size());

    std::vector<bool> inserted(smalls.size(), false);

    for (size_t i = 0; i < order.size(); i++)
    {
        size_t idx = order[i];
        if (idx < smalls.size() && !inserted[idx])
        {
            binaryInsertVector(vec, smalls[idx]);
            inserted[idx] = true;
        }
    }

    for (size_t i = 0; i < smalls.size(); i++)
        if (!inserted[i])
            binaryInsertVector(vec, smalls[i]);
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& deq)
{
    if (deq.size() <= 1)
        return;

    std::vector<int> bigs;
    std::vector<int> smalls;

    for (size_t i = 0; i + 1 < deq.size(); i += 2)
    {
        if (deq[i] < deq[i + 1])
        {
            smalls.push_back(deq[i]);
            bigs.push_back(deq[i + 1]);
        }
        else
        {
            smalls.push_back(deq[i + 1]);
            bigs.push_back(deq[i]);
        }
    }

    if (deq.size() % 2 == 1)
        bigs.push_back(deq.back());

    std::deque<int> tmp(bigs.begin(), bigs.end());
    fordJohnsonDeque(tmp);
    deq = tmp;

    std::vector<size_t> order = generateJacobsthalOrder(smalls.size());
    std::vector<bool> inserted(smalls.size(), false);

    for (size_t i = 0; i < order.size(); i++)
    {
        size_t idx = order[i];
        if (idx < smalls.size() && !inserted[idx])
        {
            binaryInsertDeque(deq, smalls[idx]);
            inserted[idx] = true;
        }
    }

    for (size_t i = 0; i < smalls.size(); i++)
        if (!inserted[i])
            binaryInsertDeque(deq, smalls[i]);
}