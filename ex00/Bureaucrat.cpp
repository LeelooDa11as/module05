#include "Bureaucrat.hpp"

// Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat class constructor called" << std::endl;
	//exceptions 
	return; 
}

Bureaucrat::Bureaucrat( Bureaucrat const &copy ) {
	std::cout << "Bureaucrat class copy constructor called" << std::endl;
	*this = copy;
	return;
}

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const &other ) {
	if (this != &other) {
		this->_name = other.getName();
		this->_grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout << "Bureaucrat classs destructor called" << std::endl;
	return;
}

std::string	Bureaucrat::getName( void ) const {
	return this->_name;
}

int			Bureaucrat::getGrade( void ) const {
	return this->_grade;
}

void		Bureaucrat::increment ( int points ) {
	this->_grade -= points;
	return;;
}

void		Bureaucrat::decrement (int points) {
	this->_grade += points;
	return;
}
