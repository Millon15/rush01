#ifndef CPU_HPP
#define CPU_HPP

#include <module.hpp>

class CPU : public module {

public:
	CPU( void );
	CPU( std::string, int );
	CPU( const CPU & );
	~CPU( void );

	CPU			&operator=( const CPU & );

private:


};

#endif												// end of CPU_HPP
