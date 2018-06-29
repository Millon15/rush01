#include <CPU.hpp>

CPU::CPU( void )
{
	return ;
}
CPU::CPU( std::string a, int b ) : module(a, b)
{
	return ;
}
CPU::CPU( const CPU &toCopy )
{
	*this = toCopy;
}
CPU::~CPU( void )
{
	return ;
}

CPU			&CPU::operator=( const CPU &toCopy )
{
	module::operator=(toCopy);
	static_cast<void>(toCopy);

	return *this;
}
