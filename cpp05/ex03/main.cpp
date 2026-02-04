#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    std::cout << "========== INTERN FORM FACTORY TEST ==========\n\n";

    Intern intern;

    Bureaucrat boss("Boss", 1);
    Bureaucrat internBoy("InternBoy", 150);

    AForm* form1 = NULL;
    AForm* form2 = NULL;
    AForm* form3 = NULL;
    AForm* form4 = NULL;

    std::cout << "\n--- Creating valid forms ---\n";
    form1 = intern.makeForm("shrubbery creation", "home");
    form2 = intern.makeForm("robotomy request", "Bender");
    form3 = intern.makeForm("presidential pardon", "Arthur Dent");

    std::cout << "\n--- Creating invalid form ---\n";
    form4 = intern.makeForm("coffee making", "Office");

    std::cout << "\n========== SIGN & EXECUTE TEST ==========\n";

    if (form1)
    {
        internBoy.signForm(*form1);   // ❌ too low
        boss.signForm(*form1);        // ✅
        boss.executeForm(*form1);     // ✅
    }

    std::cout << "\n------------------------------------------\n";

    if (form2)
    {
        boss.signForm(*form2);
        internBoy.executeForm(*form2); // ❌ too low
        boss.executeForm(*form2);      // ✅ (random result)
    }

    std::cout << "\n------------------------------------------\n";

    if (form3)
    {
        boss.signForm(*form3);
        boss.executeForm(*form3);
    }

    std::cout << "\n========== CLEANUP ==========\n";

    delete form1;
    delete form2;
    delete form3;
    delete form4;

    std::cout << "\n========== END OF TEST ==========\n";

    return 0;
}
