#ifndef TIME_HPP
#define TIME_HPP

#include <module.hpp>

class Time : public module {

public:
	Time( void );
	Time( std::string, int );
	Time( const Time & );
	~Time( void );

	Time			&operator=( const Time & );

private:


};

#endif												// end of TIME_HPP
