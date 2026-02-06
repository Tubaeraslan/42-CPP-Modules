#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[3])(const std::string&) = {
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formTypes[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }

    std::cout << "Intern could not find the form: " << formName << std::endl;
    return NULL;
}