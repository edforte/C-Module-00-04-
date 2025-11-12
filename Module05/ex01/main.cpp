#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	std::cout << "=== TEST 1: Valid Form Creation ===" << std::endl;
	try {
		Form contract("Contract", 50, 25);
		std::cout << contract << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 2: Form Grade Too High ===" << std::endl;
	try {
		Form invalid("Invalid", 0, 50);
		std::cout << invalid << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 3: Form Grade Too Low ===" << std::endl;
	try {
		Form invalid("Invalid", 151, 50);
		std::cout << invalid << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 4: Successful Form Signing ===" << std::endl;
	try {
		Bureaucrat boss("Boss", 10);
		Form contract("Contract", 20, 10);
		std::cout << contract << std::endl;
		boss.signForm(contract);
		std::cout << contract << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 5: Failed Form Signing (Grade Too Low) ===" << std::endl;
	try {
		Bureaucrat intern("Intern", 100);
		Form importantDoc("Important Document", 50, 25);
		std::cout << importantDoc << std::endl;
		intern.signForm(importantDoc);
		std::cout << importantDoc << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 6: Multiple Signing Attempts ===" << std::endl;
	try {
		Bureaucrat ceo("CEO", 1);
		Bureaucrat manager("Manager", 50);
		Form permit("Building Permit", 40, 30);
		
		std::cout << permit << std::endl;
		manager.signForm(permit);
		std::cout << permit << std::endl;
		ceo.signForm(permit);
		std::cout << permit << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 7: Edge Cases ===" << std::endl;
	try {
		Bureaucrat perfect("Perfect", 1);
		Form easyForm("Easy Form", 150, 150);
		Form hardForm("Hard Form", 1, 1);
		
		std::cout << easyForm << std::endl;
		perfect.signForm(easyForm);
		
		std::cout << hardForm << std::endl;
		perfect.signForm(hardForm);
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}
