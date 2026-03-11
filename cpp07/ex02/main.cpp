// #include <iostream>
// #include <string>
// #include "Array.hpp"

// int main()
// {
//     std::cout << "===== EMPTY ARRAY TEST =====\n";

//     Array<int> empty;
//     std::cout << "Size: " << empty.size() << std::endl;

//     std::cout << "\n===== CONSTRUCTOR(n) TEST =====\n";

//     Array<int> numbers(5);

//     std::cout << "Size: " << numbers.size() << std::endl;

//     std::cout << "Default values:\n";
//     for (size_t i = 0; i < numbers.size(); i++)
//         std::cout << numbers[i] << " ";
//     std::cout << std::endl;

//     std::cout << "\n===== MODIFY VALUES TEST =====\n";

//     for (size_t i = 0; i < numbers.size(); i++)
//         numbers[i] = i * 10;

//     for (size_t i = 0; i < numbers.size(); i++)
//         std::cout << numbers[i] << " ";
//     std::cout << std::endl;

//     std::cout << "\n===== OUT OF BOUNDS TEST =====\n";

//     try
//     {
//         std::cout << numbers[10] << std::endl;
//     }
//     catch (std::exception &e)
//     {
//         std::cout << "Exception caught: " << e.what() << std::endl;
//     }

//     std::cout << "\n===== COPY CONSTRUCTOR TEST =====\n";

//     Array<int> copy(numbers);

//     std::cout << "Copy values:\n";
//     for (size_t i = 0; i < copy.size(); i++)
//         std::cout << copy[i] << " ";
//     std::cout << std::endl;

//     std::cout << "\n===== DEEP COPY TEST =====\n";

//     numbers[0] = 999;

//     std::cout << "Original[0]: " << numbers[0] << std::endl;
//     std::cout << "Copy[0]: " << copy[0] << std::endl;

//     std::cout << "\n===== ASSIGNMENT OPERATOR TEST =====\n";

//     Array<int> assign;
//     assign = numbers;

//     for (size_t i = 0; i < assign.size(); i++)
//         std::cout << assign[i] << " ";
//     std::cout << std::endl;

//     std::cout << "\n===== STRING ARRAY TEST =====\n";

//     Array<std::string> words(3);

//     words[0] = "Hello";
//     words[1] = "42";
//     words[2] = "World";

//     for (size_t i = 0; i < words.size(); i++)
//         std::cout << words[i] << " ";
//     std::cout << std::endl;

//     std::cout << "\n===== TEST FINISHED =====\n";

//     return 0;
// }

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}