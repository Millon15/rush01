#ifndef TIME_HPP
#define TIME_HPP

#include <ACursesModule.hpp>

class Time : public ACursesModule {

public:
	Time( void );
	Time( std::string, int );
	Time( const Time & );
	~Time( void );

	Time			&operator=( const Time & );

	void			putInfo( void ) const;

private:


};

#endif												// end of TIME_HPP
