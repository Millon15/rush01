#ifndef NAME_HPP
#define NAME_HPP

#include <ACursesModule.hpp>
#include <unistd.h>

class Name : public ACursesModule {

public:
	Name( void );
	Name( std::string, int );
	Name( const Name & );
	~Name( void );

	Name			&operator=( const Name & );

	virtual void			putInfo( void ) const;

private:


};

#endif												// end of NAME_HPP
