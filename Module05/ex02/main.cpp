#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	std::cout << "=== TEST 1: ShrubberyCreationForm ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 137);
		ShrubberyCreationForm shrub("home");
		
		std::cout << shrub << std::endl;
		bob.signForm(shrub);
		std::cout << shrub << std::endl;
		bob.executeForm(shrub);
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 2: RobotomyRequestForm Success ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 1);
		RobotomyRequestForm robot("Bender");
		
		std::cout << robot << std::endl;
		alice.signForm(robot);
		alice.executeForm(robot);
		alice.executeForm(robot);  // Try again to see different result
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 3: PresidentialPardonForm ===" << std::endl;
	try {
		Bureaucrat ceo("CEO", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		
		std::cout << pardon << std::endl;
		ceo.signForm(pardon);
		ceo.executeForm(pardon);
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 4: Execution Without Signing ===" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm unsigned_pardon("Zaphod");
		
		std::cout << unsigned_pardon << std::endl;
		boss.executeForm(unsigned_pardon);  // Should fail
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 5: Insufficient Grade to Execute ===" << std::endl;
	try {
		Bureaucrat lowly("Lowly", 140);
		Bureaucrat signer("Signer", 1);
		ShrubberyCreationForm shrub2("garden");
		
		std::cout << shrub2 << std::endl;
		signer.signForm(shrub2);
		lowly.executeForm(shrub2);  // Should fail
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 6: Insufficient Grade to Sign ===" << std::endl;
	try {
		Bureaucrat intern("Intern", 100);
		PresidentialPardonForm important("Important Person");
		
		std::cout << important << std::endl;
		intern.signForm(important);  // Should fail
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 7: All Forms with CEO ===" << std::endl;
	try {
		Bureaucrat ceo("CEO", 1);
		ShrubberyCreationForm shrub("office");
		RobotomyRequestForm robot("Employee");
		PresidentialPardonForm pardon("Criminal");
		
		std::cout << "\n--- Shrubbery ---" << std::endl;
		ceo.signForm(shrub);
		ceo.executeForm(shrub);
		
		std::cout << "\n--- Robotomy ---" << std::endl;
		ceo.signForm(robot);
		ceo.executeForm(robot);
		
		std::cout << "\n--- Presidential Pardon ---" << std::endl;
		ceo.signForm(pardon);
		ceo.executeForm(pardon);
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 8: Edge Case - Grade Boundaries ===" << std::endl;
	try {
		Bureaucrat b145("B145", 145);
		Bureaucrat b137("B137", 137);
		ShrubberyCreationForm shrub("boundary");
		
		std::cout << shrub << std::endl;
		b145.signForm(shrub);  // Should succeed (grade 145 required)
		b137.executeForm(shrub);  // Should succeed (grade 137 required)
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}
