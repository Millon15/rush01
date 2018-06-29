#ifndef CPU_HPP
#define CPU_HPP

#include <ACursesModule.hpp>

class CPU : public ACursesModule {

public:
	CPU( void );
	CPU( std::string, int );
	CPU( const CPU & );
	~CPU( void );

	CPU			&operator=( const CPU & );

	void		putInfo( void ) const;

private:


};

#endif												// end of CPU_HPP
