#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private:
	// Form creation function pointer type
	typedef AForm* (*FormCreator)(const std::string& target);
	
	// Structure to hold form name and creator function
	struct FormType {
		std::string name;
		FormCreator creator;
	};
	
	// Static array of form types
	static FormType _formTypes[3];
	
	// Static creator functions
	static AForm* createShrubberyForm(const std::string& target);
	static AForm* createRobotomyForm(const std::string& target);
	static AForm* createPresidentialForm(const std::string& target);

public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();
	
	AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif
