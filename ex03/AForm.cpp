#include "../inc/AForm.hpp"
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"

AForm::AForm(void) : _name("Default"), _signed(false), _sign_grade(1), _execute_grade(1) {
    std::cout << GREEN << "Form class default constructor called" << RESET << std::endl;
    return;
}

AForm::AForm(const std::string &name, const int &sign_grade, const int &execute_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade) {
    std::cout << GREEN << "Form class full constructor called" << RESET << std::endl;
    if (_sign_grade < 1 || _execute_grade < 1)
        throw GradeTooHighException();
    else if (_sign_grade > 150 || _execute_grade > 150)
        throw GradeTooLowException();
    return;
}

AForm::AForm(AForm const &base) : _name(base._name), _signed(base._signed), _sign_grade(base._sign_grade), _execute_grade(base._execute_grade)  {
    std::cout << GREEN <<"Form class copy constructor called" << RESET << std::endl;
    return;
}

AForm& AForm::operator=(AForm const &other) {
    std::cout << GREEN << "Form assignment operator called" << RESET << std::endl;
    if (this != &other) {
        this->_signed = other._signed;
    }
    return *this;
}

AForm::~AForm(void) {
    std::cout << RED << "Form class destructor called" << RESET << std::endl;
    return;
}

const std::string&  AForm::getName(void) const {
	return this->_name;
}

bool				AForm::getSigned(void) const {
    return  this->_signed;
}

const int&		   	AForm::getSignGrade(void) const {
    return  this->_sign_grade;
}

const int&			AForm::getExecuteGrade(void) const {
    return  this->_execute_grade;
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

void         AForm::beSigned(Bureaucrat const &office_rat) {
    if (office_rat.getGrade() <= this->_sign_grade && this->_signed == false) {
        this->_signed = true;
        std::cout << YELLOW << office_rat.getName() << " signed " << this->_name << RESET<< std::endl;
    }
    else if (office_rat.getGrade() > _sign_grade)
        throw GradeTooLowException();
}

void        AForm::exec_prep(Bureaucrat const &office_rat) const {
    if (!this->_signed)
        throw FormNotSignedException();
    if (office_rat.getGrade() > this->getExecuteGrade())
        throw GradeTooLowException();
    return;
   
}

std::ostream& operator<<(std::ostream& os, AForm const& b) {
    os << b.getName() << " sign grade is: " << b.getSignGrade() << ",\nexecute grade is: " << b.getExecuteGrade() << ",\n" << b.getName();
    if (b.getSigned())
        os << " is signed.";
    else {
        os << " is not signed";
    }
	return os;
}