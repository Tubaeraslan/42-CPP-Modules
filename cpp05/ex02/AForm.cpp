#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    // Default constructor
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    // Copy constructor
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
        // name, gradeToSign, and gradeToExecute are const and cannot be assigned
    }
    return *this;
}

AForm::~AForm() {
    // Destructor
}

std::string AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form Exception: Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form Exception: Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << f.getGradeToSign()
       << ", Grade to Execute: " << f.getGradeToExecute();
    return os;
}


