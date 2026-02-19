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


    std::cout << "\n========== END OF TESTS ==========" << std::endl;
    return 0;
}
