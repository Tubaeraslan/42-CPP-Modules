#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    // Default constructor
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw Form::GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    // Copy constructor
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
        // name, gradeToSign, and gradeToExecute are const and cannot be assigned
    }
    return *this;
}

Form::~Form() {
    // Destructor
}

std::string Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign) {
        throw Form::GradeTooLowException();
    }
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form Exception: Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form Exception: Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << f.getGradeToSign()
       << ", Grade to Execute: " << f.getGradeToExecute();
    return os;
}


