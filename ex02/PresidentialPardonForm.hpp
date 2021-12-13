#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include <fstream>

class PresidentialPardonForm : public Form {

	private:

		const int		 	_execGrade;
		std::string			_target;

		PresidentialPardonForm();

	public:

		~PresidentialPardonForm();
		PresidentialPardonForm( const std::string& target );
		PresidentialPardonForm( const PresidentialPardonForm& rhs );

		PresidentialPardonForm&	operator=( const PresidentialPardonForm& obj );

		virtual void		execute( Bureaucrat const & executor ) const;

		int					get_execGrade() const;
		const std::string&	get_target() const;
};

#endif
