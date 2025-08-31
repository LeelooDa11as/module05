/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kate <kate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:25:05 by kkoval            #+#    #+#             */
/*   Updated: 2025/08/31 20:45:45 by kate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"


Bureaucrat::Bureaucrat( void ) : _name("default"), _grade(150) {
	std::cout << GREEN << this->_name << " Bureaucrat class default constructor called" << RESET << std::endl;
	return; 
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << GREEN << this->_name << " Bureaucrat class full constructor called" << RESET << std::endl;
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
	return; 
}

Bureaucrat::Bureaucrat( Bureaucrat const &copy ) : _name(copy._name), _grade(copy._grade) {
	std::cout << GREEN << this->_name << " Bureaucrat class copy constructor called" << RESET << std::endl;
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


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() <<  ".";
    return os;
}
