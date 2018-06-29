#include <Name.hpp>

Name::Name( void )
{
	return ;
}
Name::Name( std::string a, int b ) : module(a, b)
{
	return ;
}
Name::Name( const Name &toCopy )
{
	*this = toCopy;
}
Name::~Name( void )
{
	return ;
}

Name			&Name::operator=( const Name &toCopy )
{
	module::operator=(toCopy);
	static_cast<void>(toCopy);

	return *this;
}
