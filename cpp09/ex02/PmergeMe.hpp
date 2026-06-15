#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int>  _deque;

        void parseInput(char **argv);

        void fordJohnsonVector(std::vector<int>& vec);
        void fordJohnsonDeque(std::deque<int>& deq);

        void binaryInsertVector(std::vector<int>& vec, int value);
        void binaryInsertDeque(std::deque<int>& deq, int value);

        bool isValidNumber(const std::string& str);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void process(char **argv);

        void printBefore() const;
        void printAfter() const;

        double sortVector();
        double sortDeque();
};

#endif