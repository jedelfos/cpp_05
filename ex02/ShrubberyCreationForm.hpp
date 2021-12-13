#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form {

	private:

		const int		 	_execGrade;
		std::string			_target;

		ShrubberyCreationForm();

	public:

		~ShrubberyCreationForm();
		ShrubberyCreationForm( const std::string& target );
		ShrubberyCreationForm( const ShrubberyCreationForm& rhs );

		ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& obj );

		virtual void		execute( Bureaucrat const & executor ) const;

		int					get_execGrade() const;
		const std::string&	get_target() const;
};

#endif
