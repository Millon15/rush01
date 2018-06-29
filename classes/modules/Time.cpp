#include <Time.hpp>

Time::Time( void )
{
	return ;
}
Time::Time( std::string a, int b ) : module(a, b)
{
	return ;
}
Time::Time( const Time &toCopy )
{
	*this = toCopy;
}
Time::~Time( void )
{
	return ;
}

Time			&Time::operator=( const Time &toCopy )
{
	module::operator=(toCopy);
	static_cast<void>(toCopy);

	return *this;
}
