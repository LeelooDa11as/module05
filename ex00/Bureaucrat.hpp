#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
	const std::string	_name;
	int					_grade;

	public:
	Bureaucrat( std::string _name, int grade ); //1 max-150 lowest
	Bureaucrat( Bureaucrat const &copy );
	Bureaucrat &operator=( Bureaucrat const &other );
	~Bureaucrat( void );

	std::string	getName( void ) const;
	int			getGrade( void ) const;
	void		increment( int points );
	void		decrement( int points );
};

#endif