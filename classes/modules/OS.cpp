#include <OS.hpp>

OS::OS( void )
{
	return ;
}
OS::OS( std::string a, int b ) : module(a, b)
{
	return ;
}
OS::OS( const OS &toCopy )
{
	*this = toCopy;
}
OS::~OS( void )
{
	return ;
}

OS			&OS::operator=( const OS &toCopy )
{
	module::operator=(toCopy);
	static_cast<void>(toCopy);

	return *this;
}
