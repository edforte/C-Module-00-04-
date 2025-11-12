#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	
	static const int	HIGHEST_GRADE = 1;
	static const int	LOWEST_GRADE = 150;

protected:
	// Protected method for concrete classes to implement
	virtual void executeAction() const = 0;

public:
	// Orthodox Canonical Form
	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();
	
	// Getters
	const std::string&	getName() const;
	bool				isSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	
	// Methods
	void	beSigned(const Bureaucrat& bureaucrat);
	void	execute(const Bureaucrat& executor) const;
	
	// Exception classes
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	
	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
