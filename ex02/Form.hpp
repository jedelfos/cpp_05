#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	protected:

		Form( void );

	private:

		const std::string	_name;
		const int			_grade;
		bool				_signed;


	public:

		Form( const std::string& name, int grade, bool is_signed = 0 );
		Form( const Form& obj );
		virtual ~Form();

		Form&				operator=( const Form& rhs );

		virtual void		execute( Bureaucrat const & executor ) const = 0;
		void				beSigned( const Bureaucrat& obj );

		Form&				set_signed( bool boolean );
		const std::string&	get_name( void ) const;
		int					get_grade( void ) const;
		bool				is_signed( void ) const;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class FormAlreadySignedException : public std::exception {
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};

		class BureaucratGradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream&		operator<<( std::ostream& os, const Form& rhs );

#endif
