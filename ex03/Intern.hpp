#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:

		typedef Form*	(Intern::*func)( const std::string& target );
		func			_f[3];

	public:

		Intern();
		Intern( const Intern& obj );
		~Intern();

		Intern& operator=( const Intern& rhs );

		Form*	makeForm( const std::string& name, const std::string& target );

		Form*	Smake( const std::string& target );
		Form*	Rmake( const std::string& target );
		Form*	Pmake( const std::string& target );

};



#endif
