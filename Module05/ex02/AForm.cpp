#include "AForm.hpp"

// Orthodox Canonical Form
AForm::AForm() : _name("default"), _signed(false), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE) {
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) 
	: _name(other._name), _signed(other._signed), 
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		// _name, _gradeToSign, _gradeToExecute are const and cannot be reassigned
		_signed = other._signed;
	}
	return *this;
}

AForm::~AForm() {
}

// Getters
const std::string& AForm::getName() const {
	return _name;
}

bool AForm::isSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

// Methods
void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(const Bureaucrat& executor) const {
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

// Exception classes
const char* AForm::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

// Insertion operator overload
std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "Form " << form.getName() 
	   << " [Signed: " << (form.isSigned() ? "Yes" : "No")
	   << ", Grade to sign: " << form.getGradeToSign()
	   << ", Grade to execute: " << form.getGradeToExecute() << "]";
	return os;
}
