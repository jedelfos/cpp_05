#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _execGrade(137), _target("") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& rhs )
	: Form(rhs.get_name(), rhs.get_grade(), false), _execGrade(137), _target(rhs.get_target()) {
	*this = rhs;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target )
	: Form("ShrubberyCreationForm", 147, false), _execGrade(137), _target(target) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& obj ) {
	if (this == &obj)
		return *this;

	set_signed(obj.is_signed());
	_target = obj.get_target();
	return *this;
}

void					ShrubberyCreationForm::execute( const Bureaucrat& executor ) const {
	if (is_signed() == false) {
		throw Form::FormNotSignedException();
	}
	else if (get_execGrade() < executor.get_grade()) {
		throw Form::BureaucratGradeTooLowException();
	}
	else {
		std::ofstream	ofs;
		ofs.open((get_target() + "_shrubbery").c_str());
		if (!ofs.is_open()) {
			std::cerr << "Failed to open file '" << get_target() + "_shrubbery" << '\'' << std::endl;
		} else {
			ofs << std::endl <<
			"              # #### ####" << std::endl <<
			"            ### \\/#|### |/####" << std::endl <<
			"           ##\\/#/ \\||/##/_/##/_#" << std::endl <<
			"         ###  \\/###|/ \\/ # ###" << std::endl <<
			"       ##_\\_#\\_\\## | #/###_/_####" << std::endl <<
			"      ## #### # \\ #| /  #### ##/##" << std::endl <<
			"       __#_--###`  |{,###---###-~" << std::endl <<
			"                 \\ }{" << std::endl <<
			"                  }}{" << std::endl <<
			"                  }}{" << std::endl <<
			"             ejm  {{}" << std::endl <<
			"            , -=-~{ .-^- _" << std::endl;
			ofs.close();
		}
	}
}

int						ShrubberyCreationForm::get_execGrade() const { return _execGrade; }

const std::string&		ShrubberyCreationForm::get_target() const { return _target; }
void					ShrubberyCreationForm::set_target( const std::string& target ) { _target = target; }
