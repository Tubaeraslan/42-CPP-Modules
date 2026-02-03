#include "Bureaucrat.hpp"

int main()
{
    std::cout << "========== BASIC VALID TEST ==========" << std::endl;
    try
    {
        Bureaucrat a("Alice", 42);
        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << "After increment: " << a << std::endl;

        a.decrementGrade();
        std::cout << "After decrement: " << a << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n========== GRADE TOO HIGH (CONSTRUCTOR) ==========" << std::endl;
    try
    {
        Bureaucrat b("Bob", 0); // invalid
        std::cout << b << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n========== GRADE TOO LOW (CONSTRUCTOR) ==========" << std::endl;
    try
    {
        Bureaucrat c("Charlie", 151); // invalid
        std::cout << c << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n========== INCREMENT LIMIT TEST ==========" << std::endl;
    try
    {
        Bureaucrat d("Diana", 1);
        std::cout << d << std::endl;

        d.incrementGrade(); // should throw
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n========== DECREMENT LIMIT TEST ==========" << std::endl;
    try
    {
        Bureaucrat e("Edward", 150);
        std::cout << e << std::endl;

        e.decrementGrade(); // should throw
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n========== COPY CONSTRUCTOR TEST ==========" << std::endl;
    try
    {
        Bureaucrat original("Original", 10);
        Bureaucrat copy(original);

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n========== COPY ASSIGNMENT OPERATOR TEST ==========" << std::endl;
    try
    {
        Bureaucrat x("Xavier", 5);
        Bureaucrat y("Yvonne", 100);

        std::cout << "Before assignment:" << std::endl;
        std::cout << "X: " << x << std::endl;
        std::cout << "Y: " << y << std::endl;

        y = x;

        std::cout << "After assignment:" << std::endl;
        std::cout << "X: " << x << std::endl;
        std::cout << "Y: " << y << std::endl;
        std::cout << "(Notice: Y keeps its own name)" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n========== END OF TESTS ==========" << std::endl;
    return 0;
}
