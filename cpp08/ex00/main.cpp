#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {
    // ===== Vector Test =====
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    std::cout << "Vector test:" << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 30); // Bulunacak
        std::cout << "Found in vector: " << *it << std::endl;

        it = easyfind(vec, 100); // Bulunamayacak
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // ===== List Test =====
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);

    std::cout << "\nList test:" << std::endl;
    try {
        std::list<int>::iterator it = easyfind(lst, 25); // Bulunacak
        std::cout << "Found in list: " << *it << std::endl;

        it = easyfind(lst, 50); // Bulunamayacak
        std::cout << "Found in list: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // ===== Deque Test =====
    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(4);
    deq.push_back(5);

    std::cout << "\nDeque test:" << std::endl;
    try {
        std::deque<int>::iterator it = easyfind(deq, 4); // Bulunacak
        std::cout << "Found in deque: " << *it << std::endl;

        it = easyfind(deq, 10); // Bulunamayacak
        std::cout << "Found in deque: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}