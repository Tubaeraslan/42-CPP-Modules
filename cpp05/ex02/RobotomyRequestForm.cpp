#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), target(target) {
    std::srand(std::time(0)); // Seed for randomness
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    checkExecute(executor);

    std::cout << "Bzzzz... Vrrrrr... (drilling noises)" << std::endl;
    if (std::rand() % 2) {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << target << "." << std::endl;
    }
}