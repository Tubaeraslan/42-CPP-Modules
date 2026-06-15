#include <iostream>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    // Test basic stack operations
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Test iteration with iterators
    std::cout << "Stack elements using iterators:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // Test stack functionality
    std::cout << "\nStack size: " << mstack.size() << std::endl;
    std::cout << "Top element: " << mstack.top() << std::endl;

    // Pop elements
    mstack.pop();
    std::cout << "After pop, top element: " << mstack.top() << std::endl;

    return 0;
}
