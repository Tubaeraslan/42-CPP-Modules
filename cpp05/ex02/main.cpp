#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);

    ShrubberyCreationForm f1("home");
    RobotomyRequestForm f2("Bender");
    PresidentialPardonForm f3("Arthur Dent");

    // Execute without signing (should fail)
    intern.executeForm(f1);

    intern.signForm(f1);
    boss.signForm(f1);
    boss.executeForm(f1);
    // Low grade execute (should fail)
    intern.executeForm(f1);

    boss.signForm(f2);
    boss.executeForm(f2);

    boss.signForm(f3);
    boss.executeForm(f3);
}
