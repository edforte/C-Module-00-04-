#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	std::cout << "=== TEST 1: Create Robotomy Request Form ===" << std::endl;
	{
		Intern someRandomIntern;
		AForm* rrf;
		
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf) {
			std::cout << *rrf << std::endl;
			
			Bureaucrat ceo("CEO", 1);
			ceo.signForm(*rrf);
			ceo.executeForm(*rrf);
			
			delete rrf;
		}
	}
	
	std::cout << "\n=== TEST 2: Create Shrubbery Creation Form ===" << std::endl;
	{
		Intern intern;
		AForm* form;
		
		form = intern.makeForm("shrubbery creation", "garden");
		if (form) {
			std::cout << *form << std::endl;
			
			Bureaucrat gardener("Gardener", 140);
			gardener.signForm(*form);
			gardener.executeForm(*form);
			
			delete form;
		}
	}
	
	std::cout << "\n=== TEST 3: Create Presidential Pardon Form ===" << std::endl;
	{
		Intern intern;
		AForm* form;
		
		form = intern.makeForm("presidential pardon", "Arthur Dent");
		if (form) {
			std::cout << *form << std::endl;
			
			Bureaucrat president("President", 1);
			president.signForm(*form);
			president.executeForm(*form);
			
			delete form;
		}
	}
	
	std::cout << "\n=== TEST 4: Invalid Form Name ===" << std::endl;
	{
		Intern intern;
		AForm* form;
		
		form = intern.makeForm("invalid form type", "Target");
		if (form == NULL) {
			std::cout << "Form creation returned NULL as expected" << std::endl;
		}
	}
	
	std::cout << "\n=== TEST 5: Create All Form Types ===" << std::endl;
	{
		Intern intern;
		Bureaucrat master("Master", 1);
		AForm* forms[3];
		std::string formNames[3] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
		};
		std::string targets[3] = {
			"office",
			"Employee",
			"Criminal"
		};
		
		for (int i = 0; i < 3; i++) {
			forms[i] = intern.makeForm(formNames[i], targets[i]);
			if (forms[i]) {
				std::cout << "\n" << *forms[i] << std::endl;
				master.signForm(*forms[i]);
				master.executeForm(*forms[i]);
			}
		}
		
		// Clean up
		for (int i = 0; i < 3; i++) {
			if (forms[i])
				delete forms[i];
		}
	}
	
	std::cout << "\n=== TEST 6: Case Sensitivity ===" << std::endl;
	{
		Intern intern;
		AForm* form;
		
		// Should fail - wrong case
		form = intern.makeForm("Robotomy Request", "Target");
		if (form == NULL) {
			std::cout << "Form creation failed as expected (case sensitive)" << std::endl;
		}
		
		// Should succeed - correct case
		form = intern.makeForm("robotomy request", "Target");
		if (form) {
			std::cout << "Form created successfully with correct case" << std::endl;
			delete form;
		}
	}
	
	std::cout << "\n=== TEST 7: Multiple Interns ===" << std::endl;
	{
		Intern intern1;
		Intern intern2;
		Intern intern3;
		
		AForm* form1 = intern1.makeForm("shrubbery creation", "Park");
		AForm* form2 = intern2.makeForm("robotomy request", "Robot");
		AForm* form3 = intern3.makeForm("presidential pardon", "Convict");
		
		Bureaucrat boss("Boss", 1);
		
		if (form1) {
			boss.signForm(*form1);
			boss.executeForm(*form1);
			delete form1;
		}
		
		if (form2) {
			boss.signForm(*form2);
			boss.executeForm(*form2);
			delete form2;
		}
		
		if (form3) {
			boss.signForm(*form3);
			boss.executeForm(*form3);
			delete form3;
		}
	}
	
	std::cout << "\n=== TEST 8: Intern Copy ===" << std::endl;
	{
		Intern intern1;
		Intern intern2(intern1);  // Copy constructor
		Intern intern3;
		intern3 = intern2;  // Assignment operator
		
		AForm* form = intern3.makeForm("robotomy request", "Test");
		if (form) {
			std::cout << "Form created by copied intern" << std::endl;
			delete form;
		}
	}
	
	return 0;
}
