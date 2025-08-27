/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:25:29 by kkoval            #+#    #+#             */
/*   Updated: 2025/08/27 16:25:58 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#define RESET	"\033[0m"
#define BLUE	"\033[38;5;117m"

int	main( void ) 
{
	std::cout << BLUE << "--------------------Grade Tests--------------------" << RESET << std::endl;
	try {
		Bureaucrat one("Alice", 0);
		one.increment(1);
		std::cout << one << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
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
	
	std::cout << BLUE << "--------------------Constructor Tests--------------------" << RESET << std::endl;

	Bureaucrat *Janice = new  Bureaucrat("Janice", 23);
	std::cout << Janice->getName() << std::endl;
	std::cout << Janice->getGrade() << std::endl;
	
	Bureaucrat			Chandler;
	Chandler = *Janice;
	std::cout << Chandler.getName() << std::endl;
	std::cout << Chandler.getGrade() << std::endl;

	Bureaucrat	Steve(Chandler);
	std::cout << Steve.getName() << std::endl;
	std::cout << Steve.getGrade() << std::endl;
	
	Janice->increment(10);
	Chandler.increment(3);
	Steve.decrement(7);
	
	std::cout << "Janice's grade now is --> " << Janice->getGrade() << std::endl;
	std::cout << "Chandler's grade now is --> " << Chandler.getGrade() << std::endl;
	std::cout << "Steve's grade now is --> " << Steve.getGrade() << std::endl;
	
	delete Janice;
	
	return 0;
}
