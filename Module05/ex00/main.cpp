#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	std::cout << "=== TEST 1: Valid Bureaucrat Creation ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 50);
		std::cout << bob << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 2: Grade Too High Exception ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 3: Grade Too Low Exception ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 4: Increment Grade ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 2);
		std::cout << "Before increment: " << alice << std::endl;
		alice.incrementGrade();
		std::cout << "After increment: " << alice << std::endl;
		alice.incrementGrade();  // Should throw exception
		std::cout << "After second increment: " << alice << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 5: Decrement Grade ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 149);
		std::cout << "Before decrement: " << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << "After decrement: " << charlie << std::endl;
		charlie.decrementGrade();  // Should throw exception
		std::cout << "After second decrement: " << charlie << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 6: Copy Constructor ===" << std::endl;
	try {
		Bureaucrat original("Original", 75);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== TEST 7: Assignment Operator ===" << std::endl;
	try {
		Bureaucrat first("First", 100);
		Bureaucrat second("Second", 50);
		std::cout << "Before assignment:" << std::endl;
		std::cout << "First: " << first << std::endl;
		std::cout << "Second: " << second << std::endl;
		first = second;
		std::cout << "After assignment:" << std::endl;
		std::cout << "First: " << first << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}
