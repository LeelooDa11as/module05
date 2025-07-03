/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:25:18 by kkoval            #+#    #+#             */
/*   Updated: 2025/07/03 17:52:37 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Form;
class Bureaucrat
{
	private:
	const std::string	_name;
	int					_grade;

	public:
	Bureaucrat( void ); // maybe should not exist because problematic grade
	Bureaucrat( std::string _name, int grade ); //1 max-150 lowest
	Bureaucrat( Bureaucrat const &copy );
	Bureaucrat &operator=( Bureaucrat const &other );
	~Bureaucrat( void );

	std::string	getName( void ) const;
	int			getGrade( void ) const;
	void		increment( int points );
	void		decrement( int points );
	void		signForm(Form &paper);

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
};

#include "Form.hpp"

std::ostream& operator<<(std::ostream& os, Bureaucrat const& b);

#endif