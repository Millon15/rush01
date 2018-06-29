#ifndef RAM_HPP
#define RAM_HPP

#include <module.hpp>

class RAM : public module {

public:
	RAM( void );
	RAM( std::string, int );
	RAM( const RAM & );
	~RAM( void );

	RAM			&operator=( const RAM & );

private:


};

#endif												// end of RAM_HPP
