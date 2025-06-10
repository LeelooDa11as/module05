/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:25:05 by kkoval            #+#    #+#             */
/*   Updated: 2025/06/10 17:25:08 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) {
	std::cout << "Bureaucrat class constructor called" << std::endl;
	return; 
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat class constructor called" << std::endl;
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
	return; 
}

Bureaucrat::Bureaucrat( Bureaucrat const &copy ) {
	std::cout << "Bureaucrat class copy constructor called" << std::endl;
	*this = copy;
	return;
}

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const &other ) {
	if (this != &other) {
		//this->_name = other.getName();
		this->_grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout << "Bureaucrat classs destructor called" << std::endl;  
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
	return;;
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
