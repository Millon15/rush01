#ifndef NAME_HPP
#define NAME_HPP

#include <module.hpp>

class Name : public module {

public:
	Name( void );
	Name( std::string, int );
	Name( const Name & );
	~Name( void );

	Name			&operator=( const Name & );

private:


};

#endif												// end of NAME_HPP
