#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    checkExecute(executor);

    std::ofstream outFile(target + "_shrubbery");
    if (!outFile) {
        throw std::runtime_error("Error: Could not create file " + target + "_shrubbery");
    }

    outFile <<
        "       _-_\n"
        "    /~~   ~~\\\n"
        " /~~         ~~\\\n"
        "{               }\n"
        " \\  _-     -_  /\n"
        "   ~  \\\\ //  ~\n"
        "_- -   | | _- _\n"
        "  _ -  | |   -_\n"
        "      // \\\\\n";

    outFile.close();
}