#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

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

PmergeMe::~PmergeMe() {}

void PmergeMe::process(char **argv)
{
    parseInput(argv);

    printBefore();

    double t1 = sortVector();
    double t2 = sortDeque();

    printAfter();

    std::cout << "Time to process vector : " << t1 << " us\n";
    std::cout << "Time to process deque  : " << t2 << " us\n";
}

// ================= INPUT VALIDATION =================

bool PmergeMe::isValidNumber(const std::string& s)
{
    if (s.empty()) return false;

    for (size_t i = 0; i < s.size(); i++)
        if (!std::isdigit(s[i]))
            return false;

    long n = std::atol(s.c_str());
    return (n >= 0 && n <= INT_MAX);
}

void PmergeMe::parseInput(char **argv)
{
    for (int i = 1; argv[i]; i++)
    {
        std::string s(argv[i]);

        if (!isValidNumber(s))
            throw std::runtime_error("Error");

        int n = std::atoi(s.c_str());

        _vector.push_back(n);
        _deque.push_back(n);
    }
}

// ================= PRINT =================

void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); i++)
    {
        std::cout << _vector[i];
        if (i + 1 != _vector.size()) std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); i++)
    {
        std::cout << _vector[i];
        if (i + 1 != _vector.size()) std::cout << " ";
    }
    std::cout << std::endl;
}

// ================= TIMER (C++98) =================

double PmergeMe::sortVector()
{
    clock_t start = clock();
    fordJohnsonVector(_vector);
    clock_t end = clock();

    return (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

double PmergeMe::sortDeque()
{
    clock_t start = clock();
    fordJohnsonDeque(_deque);
    clock_t end = clock();

    return (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

// ================= BINARY INSERT =================

void PmergeMe::binaryInsertVector(std::vector<int>& v, int val)
{
    size_t l = 0, r = v.size();

    while (l < r)
    {
        size_t m = (l + r) / 2;
        if (v[m] < val)
            l = m + 1;
        else
            r = m;
    }
    v.insert(v.begin() + l, val);
}

void PmergeMe::binaryInsertDeque(std::deque<int>& d, int val)
{
    size_t l = 0, r = d.size();

    while (l < r)
    {
        size_t m = (l + r) / 2;
        if (d[m] < val)
            l = m + 1;
        else
            r = m;
    }
    d.insert(d.begin() + l, val);
}

// ================= JACOBSTHAL =================

std::vector<size_t> PmergeMe::jacobsthalIndices(size_t n)
{
    std::vector<size_t> order;
    if (n == 0) return order;

    std::vector<size_t> jac;
    jac.push_back(0);
    jac.push_back(1);

    while (true)
    {
        size_t next = jac[jac.size() - 1] + 2 * jac[jac.size() - 2];
        if (next >= n) break;
        jac.push_back(next);
    }

    std::vector<bool> used(n, false);

    for (size_t i = 1; i < jac.size(); i++)
    {
        size_t idx = jac[i];
        if (idx < n && !used[idx])
        {
            order.push_back(idx);
            used[idx] = true;
        }
    }

    for (size_t i = 0; i < n; i++)
        if (!used[i])
            order.push_back(i);

    return order;
}

// ================= FORD-JOHNSON VECTOR =================

void PmergeMe::fordJohnsonVector(std::vector<int>& v)
{
    if (v.size() <= 1)
        return;

    std::vector<int> big, small;

    for (size_t i = 0; i + 1 < v.size(); i += 2)
    {
        if (v[i] < v[i + 1])
        {
            small.push_back(v[i]);
            big.push_back(v[i + 1]);
        }
        else
        {
            small.push_back(v[i + 1]);
            big.push_back(v[i]);
        }
    }

    if (v.size() % 2 == 1)
        big.push_back(v.back());

    fordJohnsonVector(big);
    v = big;

    std::vector<size_t> order = jacobsthalIndices(small.size());

    for (size_t i = 0; i < order.size(); i++)
        binaryInsertVector(v, small[order[i]]);
}

// ================= FORD-JOHNSON DEQUE =================

void PmergeMe::fordJohnsonDeque(std::deque<int>& d)
{
    if (d.size() <= 1)
        return;

    std::vector<int> big, small;

    for (size_t i = 0; i + 1 < d.size(); i += 2)
    {
        if (d[i] < d[i + 1])
        {
            small.push_back(d[i]);
            big.push_back(d[i + 1]);
        }
        else
        {
            small.push_back(d[i + 1]);
            big.push_back(d[i]);
        }
    }

    if (d.size() % 2 == 1)
        big.push_back(d.back());

    std::deque<int> tmp(big.begin(), big.end());
    fordJohnsonDeque(tmp);
    d = tmp;

    std::vector<size_t> order = jacobsthalIndices(small.size());

    for (size_t i = 0; i < order.size(); i++)
        binaryInsertDeque(d, small[order[i]]);
}