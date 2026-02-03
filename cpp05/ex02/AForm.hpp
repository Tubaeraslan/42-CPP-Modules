#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;  // Forward declaration

class AForm{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();

        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat& b);

        // Exception classes
        class GradeTooHighException : public std::exception{
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif