/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kate <kate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:25:29 by kkoval            #+#    #+#             */
/*   Updated: 2025/08/31 22:30:05 by kate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RESET	"\033[0m"
#define BLUE	"\033[38;5;117m"

int	main( void ) 
{
	std::cout << BLUE << "--------------------Constructor Tests--------------------" << RESET << std::endl;
	try {
		Bureaucrat	Polly("Polly", 10);
		Form		separation_papers("divorce", 9, 9);		
		Polly.signForm(separation_papers);
		Polly.increment(1);
		Polly.signForm(separation_papers);
		std::cout << Polly << std::endl;
		std::cout << separation_papers << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::cout << "!!!!!!!!!!!!!!!!" << std::endl; // should not enter as Bureaucrat catches the Form exceptions
	}
	
	try {
		Bureaucrat	two("Janice", 151);
		two.decrement(10);
		std::cout << two << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	Bureaucrat	three("Poppy", 75);
	std::cout << three << std::endl;
	try {
		three.increment(60);
		std::cout << three << std::endl;
		three.decrement(10);
		std::cout << three << std::endl;
		three.increment(25);
		std::cout << three << std::endl;
		three.increment(20);
		std::cout << three << std::endl;

	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	try {
		Bureaucrat	four("Polly", 50);
		
		std::cout << four << std::endl;
		four = three;
		std::cout << four << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		Bureaucrat five(three);
		
		std::cout << five << std::endl;
	}
	
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	return 0;
}
