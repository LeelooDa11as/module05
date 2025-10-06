#include "Form.hpp"
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"

Form::Form(void) : _name("Default"), _signed(false), _sign_grade(1), _execute_grade(1){
    std::cout << GREEN << "Form class default constructor called" << RESET << std::endl;
    return;
}

Form::Form(const std::string &name, const int &sign_grade, const int &execute_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade) {
    std::cout << GREEN << "Form class full constructor called" << RESET << std::endl;
    if (_sign_grade < 1 || _execute_grade < 1)
        throw GradeTooHighException();
    else if (_sign_grade > 150 || _execute_grade > 150)
        throw GradeTooLowException();
    return;
}

Form::Form(Form const &base) : _name(base._name), _signed(base._signed), _sign_grade(base._sign_grade), _execute_grade(base._execute_grade)  {
    std::cout << GREEN <<"Form class copy constructor called" << RESET << std::endl;
    return;
}

Form& Form::operator=(Form const &other) {
    std::cout << GREEN << "Form assignment operator called" << RESET << std::endl;
    if (this != &other) {
        this->_signed = other._signed;
    }
    return *this;
}

Form::~Form(void) {
    std::cout << RED << "Form class destructor called" << RESET << std::endl;
    return;
}

const std::string&  Form::getName(void) const {
	return this->_name;
}

bool				Form::getSigned(void) const {
    return  this->_signed;
}

const int&			Form::getSignGrade(void) const {
    return  this->_sign_grade;
}

const int&			Form::getExecuteGrade(void) const {
    return  this->_execute_grade;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

void         Form::beSigned(const Bureaucrat& office_rat) {
    if (office_rat.getGrade() <= this->_sign_grade && this->_signed == false) {
        this->_signed = true;
        std::cout << YELLOW << office_rat.getName() << " signed " << this->_name << RESET<< std::endl;
    }
    else if (office_rat.getGrade() > _sign_grade)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, Form const& b) {
    os << b.getName() << " sign grade is: " << b.getSignGrade() << ", execute grade is: " << b.getExecuteGrade();
	return os;
}