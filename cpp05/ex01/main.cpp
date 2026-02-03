#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "========== BASIC FORM CREATION ==========" << std::endl;
    try
    {
        Form taxForm("Tax Form", 50, 25);
        std::cout << taxForm << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== FORM GRADE TOO HIGH ==========" << std::endl;
    try
    {
        Form invalidHigh("Invalid High", 0, 10);
        std::cout << invalidHigh << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== FORM GRADE TOO LOW ==========" << std::endl;
    try
    {
        Form invalidLow("Invalid Low", 151, 10);
        std::cout << invalidLow << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== SIGN FORM SUCCESS ==========" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        Form contract("Contract", 10, 5);

        std::cout << boss << std::endl;
        std::cout << contract << std::endl;

        boss.signForm(contract);   // should succeed

        std::cout << contract << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== SIGN FORM FAILURE ==========" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 150);
        Form secret("Secret File", 50, 20);

        std::cout << intern << std::endl;
        std::cout << secret << std::endl;

        intern.signForm(secret);   // should fail
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught in main: " << e.what() << std::endl;
    }

    std::cout << "\n========== MULTIPLE BUREAUCRATS ==========" << std::endl;
    try
    {
        Bureaucrat junior("Junior", 100);
        Bureaucrat senior("Senior", 30);

        Form report("Monthly Report", 50, 10);

        std::cout << report << std::endl;

        junior.signForm(report);   // fail
        senior.signForm(report);   // success

        std::cout << report << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== ALREADY SIGNED FORM ==========" << std::endl;
    try
    {
        Bureaucrat chief("Chief", 5);
        Form order("Executive Order", 10, 5);

        chief.signForm(order);
        chief.signForm(order); // should do nothing or print already signed behavior

        std::cout << order << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== END OF TESTS ==========" << std::endl;
    return 0;
}
