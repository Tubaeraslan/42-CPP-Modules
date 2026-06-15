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
              << " elements with std::vector : " << vectorTime
              << " us" << std::endl;

    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque : " << dequeTime
              << " us" << std::endl;
}

void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); ++i)
    {
        std::cout << _vector[i];
        if (i != _vector.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); ++i)
    {
        std::cout << _vector[i];
        if (i != _vector.size() - 1)
            std::cout << " ";
    }
        std::cout << std::endl;
}

double PmergeMe::sortVector()
{
    clock_t start = clock();
    fordJohnsonVector(_vector);
    clock_t end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

double PmergeMe::sortDeque()
{
    clock_t start = clock();
    fordJohnsonDeque(_deque);
    clock_t end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::parseInput(char **argv)
{
    for (int i = 1; argv[i] != nullptr; ++i)
    {
        std::string arg(argv[i]);
        if (!isValidNumber(arg))
        {
            std::cerr << "Error: invalid input." << std::endl;
            exit(1);
        }
        int number = std::atoi(arg.c_str());
        _vector.push_back(number);
        _deque.push_back(number);
    }
}

bool PmergeMe::isValidNumber(const std::string& str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }

    long number = std::atol(str.c_str());
    if (number < 0 || number > INT_MAX)
        return false;

    return true;
}


void PmergeMe::binaryInsertVector(std::vector<int>& vec, int value)
{
    size_t left = 0;
    size_t right = vec.size();

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;

        if (value < vec[mid])
            right = mid;
        else
            left = mid + 1;
    }

    vec.insert(vec.begin() + left, value);
}

void PmergeMe::binaryInsertDeque(std::deque<int>& deq, int value)
{
    size_t left = 0;
    size_t right = deq.size();

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;

        if (value < deq[mid])
            right = mid;
        else
            left = mid + 1;
    }

    deq.insert(deq.begin() + left, value);
}


void PmergeMe::fordJohnsonVector(std::vector<int>& vec)
{
    
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& deq)
{
    
}
