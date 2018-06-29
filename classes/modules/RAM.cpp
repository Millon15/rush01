#include <RAM.hpp>

RAM::RAM( void )
{
	return ;
}
RAM::RAM( std::string a, int b ) : module(a, b)
{
	return ;
}
RAM::RAM( const RAM &toCopy )
{
	*this = toCopy;
}
RAM::~RAM( void )
{
	return ;
}

RAM			&RAM::operator=( const RAM &toCopy )
{
	module::operator=(toCopy);
	static_cast<void>(toCopy);

	return *this;
}
