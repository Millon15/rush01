#ifndef OS_HPP
#define OS_HPP

#include <module.hpp>

class OS : public module {

public:
	OS( void );
	OS( std::string, int );
	OS( const OS & );
	~OS( void );

	OS			&operator=( const OS & );

private:


};

#endif												// end of OS_HPP
