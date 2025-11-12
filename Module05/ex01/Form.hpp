#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	
	static const int	HIGHEST_GRADE = 1;
	static const int	LOWEST_GRADE = 150;

public:
	// Orthodox Canonical Form
	Form();
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();
	
	// Getters
	const std::string&	getName() const;
	bool				isSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	
	// Methods
	void	beSigned(const Bureaucrat& bureaucrat);
	
	// Exception classes
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
