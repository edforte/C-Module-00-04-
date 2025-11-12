#include "Intern.hpp"
#include <iostream>

// Static creator functions
AForm* Intern::createShrubberyForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

// Initialize static array
Intern::FormType Intern::_formTypes[3] = {
	{"shrubbery creation", &Intern::createShrubberyForm},
	{"robotomy request", &Intern::createRobotomyForm},
	{"presidential pardon", &Intern::createPresidentialForm}
};

// Orthodox Canonical Form
Intern::Intern() {
}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {
}

// makeForm method
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	for (int i = 0; i < 3; i++) {
		if (_formTypes[i].name == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return _formTypes[i].creator(target);
		}
	}
	
	std::cout << "Error: Form type \"" << formName << "\" does not exist!" << std::endl;
	return NULL;
}
