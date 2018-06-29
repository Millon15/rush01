#ifndef RAM_HPP
#define RAM_HPP

#include <ACursesModule.hpp>

class RAM : public ACursesModule {

public:
	RAM( void );
	RAM( std::string, int );
	RAM( const RAM & );
	~RAM( void );

	RAM			&operator=( const RAM & );

	void		putInfo( void ) const;

private:


};

#endif												// end of RAM_HPP
