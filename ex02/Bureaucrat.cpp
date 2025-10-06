#include "Bureaucrat.hpp"
#include "AForm.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE	"\033[34m"  


Bureaucrat::Bureaucrat( void ) : _name("default"), _grade(150) {
	std::cout << GREEN << this->_name << " Bureaucrat class constructor called" << RESET << std::endl;
	return; 
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << GREEN << this->_name << " Bureaucrat class constructor called" << RESET << std::endl;
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
	return; 
}

Bureaucrat::Bureaucrat( Bureaucrat const &copy ) : _name(copy._name), _grade(copy._grade) {
	std::cout << GREEN << this->_name << " Bureaucrat class copy constructor called" << RESET << std::endl;
	//*this = copy;
	return;
}

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const &other ) {
	std::cout << GREEN << this->_name << " Bureaucrat assigment operator called" << RESET << std::endl;
	if (this != &other) {
		this->_grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout << RED << this->_name <<" Bureaucrat classs destructor called" << RESET << std::endl;  
	return;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::string	Bureaucrat::getName( void ) const {
	return this->_name;
}

int			Bureaucrat::getGrade( void ) const {
	return this->_grade;
}

void		Bureaucrat::increment ( int increment ) {
	if (this->_grade - increment < 1)
		throw GradeTooHighException();
	this->_grade -= increment;
	return;
}

void		Bureaucrat::decrement (int decrement) {
	if (this->_grade + decrement > 150)
		throw GradeTooLowException();
	this->_grade += decrement;
	return;
}


void		Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned( *this);
	}
	catch (const std::exception &e) {
		std::cout << BLUE << this->_name << " couldn't sign " << form.getName()  << " because of " << e.what() << RESET << std::endl;
	}
	return;
}

void		Bureaucrat::executeForm(AForm const &form) const{
	try {
		form.execute(*this);
	}
	
	catch (const std::exception &e) {
		std::cerr << this->getName() <<  " could not execute " << form.getName() << " because " << e.what() << std::endl;
		return;
	}
	std::cout << this->_name << " executed " << form.getName() << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() <<  ".";
    return os;
}
