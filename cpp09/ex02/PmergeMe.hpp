#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <climits>
#include <cctype>
#include <algorithm>
#include <chrono>
#include <stdexcept>

class PmergeMe
{
private:
    std::vector<int> _vector;
    std::deque<int>  _deque;

    void parseInput(char **argv);
    bool isValidNumber(const std::string& str);

    void fordJohnsonVector(std::vector<int>& vec);
    void fordJohnsonDeque(std::deque<int>& deq);

    void binaryInsertVector(std::vector<int>& vec, int value);
    void binaryInsertDeque(std::deque<int>& deq, int value);

    std::vector<size_t> jacobsthalIndices(size_t size);

public:
    PmergeMe();
    PmergeMe(const PmergeMe&);
    PmergeMe& operator=(const PmergeMe&);
    ~PmergeMe();

    void process(char **argv);

    void printBefore() const;
    void printAfter() const;

    double sortVector();
    double sortDeque();
};

#endif