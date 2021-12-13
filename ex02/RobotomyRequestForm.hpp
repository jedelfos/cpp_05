#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <fstream>
# include <stdlib.h>

class RobotomyRequestForm : public Form {

	private:

		const int		 	_execGrade;
		std::string			_target;

		RobotomyRequestForm();

	public:

		~RobotomyRequestForm();
		RobotomyRequestForm( const std::string& target );
		RobotomyRequestForm( const RobotomyRequestForm& rhs );

		RobotomyRequestForm&	operator=( const RobotomyRequestForm& obj );

		virtual void		execute( Bureaucrat const & executor ) const;

		int					get_execGrade() const;
		const std::string&	get_target() const;
};

#endif
