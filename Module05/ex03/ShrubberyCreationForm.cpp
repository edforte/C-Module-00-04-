#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::executeAction() const {
	std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	
	if (!outfile.is_open())
		throw std::runtime_error("Could not open file");
	
	outfile << "       ###" << std::endl;
	outfile << "      #o###" << std::endl;
	outfile << "    #####o###" << std::endl;
	outfile << "   #o#\\#|#/###" << std::endl;
	outfile << "    ###\\|/#o#" << std::endl;
	outfile << "     # }|{  #" << std::endl;
	outfile << "       }|{" << std::endl;
	outfile << std::endl;
	outfile << "      ###" << std::endl;
	outfile << "     #o###" << std::endl;
	outfile << "   #####o###" << std::endl;
	outfile << "  #o#\\#|#/###" << std::endl;
	outfile << "   ###\\|/#o#" << std::endl;
	outfile << "    # }|{  #" << std::endl;
	outfile << "      }|{" << std::endl;
	
	outfile.close();
}
