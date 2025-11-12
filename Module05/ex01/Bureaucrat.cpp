#include "Bureaucrat.hpp"
#include "Form.hpp"

// Orthodox Canonical Form
Bureaucrat::Bureaucrat() : _name("default"), _grade(LOWEST_GRADE) {
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		// _name is const, cannot be reassigned
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

// Getters
const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

// Grade modification
void Bureaucrat::incrementGrade() {
	if (_grade <= HIGHEST_GRADE)
		throw GradeTooHighException();
	_grade--;  // Lower number = higher grade
}

void Bureaucrat::decrementGrade() {
	if (_grade >= LOWEST_GRADE)
		throw GradeTooLowException();
	_grade++;  // Higher number = lower grade
}

// Form signing
void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() 
				  << " because " << e.what() << std::endl;
	}
}

// Exception classes
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

// Insertion operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
