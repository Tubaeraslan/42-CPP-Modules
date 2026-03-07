#include <iostream>
#include <string>
#include "iter.hpp"

// ---------------- PRINT FUNCTIONS ----------------

void printInt(int &x)
{
    std::cout << x << " ";
}

void printDouble(double &x)
{
    std::cout << x << " ";
}

void printChar(char &x)
{
    std::cout << x << " ";
}

void printString(std::string &x)
{
    std::cout << x << " ";
}

// ---------------- MODIFY FUNCTIONS ----------------

void addOne(int &x)
{
    x += 1;
}

void multiplyDouble(double &x)
{
    x *= 2;
}

void toUpper(char &c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

void addHello(std::string &s)
{
    s = "Hello_" + s;
}

// ---------------- MAIN TEST ----------------

int main()
{
    std::cout << "===== INT TEST =====\n";

    int intArray[5] = {1, 2, 3, 4, 5};

    std::cout << "Original: ";
    iter(intArray, 5, printInt);

    std::cout << "\nAddOne: ";
    iter(intArray, 5, addOne);
    iter(intArray, 5, printInt);

    std::cout << "\n\n===== DOUBLE TEST =====\n";

    double doubleArray[4] = {1.5, 2.5, 3.5, 4.5};

    std::cout << "Original: ";
    iter(doubleArray, 4, printDouble);

    std::cout << "\nMultiply by 2: ";
    iter(doubleArray, 4, multiplyDouble);
    iter(doubleArray, 4, printDouble);

    std::cout << "\n\n===== CHAR TEST =====\n";

    char charArray[6] = {'a','b','c','d','e','f'};

    std::cout << "Original: ";
    iter(charArray, 6, printChar);

    std::cout << "\nToUpper: ";
    iter(charArray, 6, toUpper);
    iter(charArray, 6, printChar);

    std::cout << "\n\n===== STRING TEST =====\n";

    std::string strArray[3] = {"tuba", "hello", "world"};

    std::cout << "Original: ";
    iter(strArray, 3, printString);

    std::cout << "\nAdd Hello Prefix: ";
    iter(strArray, 3, addHello);
    iter(strArray, 3, printString);

    std::cout << "\n";

    return 0;
}