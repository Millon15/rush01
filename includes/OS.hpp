#ifndef OS_HPP
#define OS_HPP

#include <ACursesModule.hpp>

class OS : public ACursesModule {

public:
	OS( void );
	OS( std::string, int );
	OS( const OS & );
	~OS( void );

	OS			&operator=( const OS & );

	void		putInfo( void ) const;

private:


};

#endif												// end of OS_HPP
