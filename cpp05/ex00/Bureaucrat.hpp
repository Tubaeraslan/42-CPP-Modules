#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
    private:
        const std::string name;
        int grade; // 1 (highest) to 150 (lowest)
    public:
        //default constructor
        Bureaucrat();
        //copy constructor
        Bureaucrat(const Bureaucrat& other);
        //copy assignment operator
        Bureaucrat& operator=(const Bureaucrat& other);
        //destructor
        ~Bureaucrat();

        Bureaucrat(const std::string& name, int grade);
        std::string getName() const;
        int getGrade() const;
        void incrementGrade(); // sayı küçüldükçe rütbe artar
        void decrementGrade(); // sayı büyüdükçe rütbe azalır

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif