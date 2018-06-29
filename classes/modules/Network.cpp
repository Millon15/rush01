#include <Network.hpp>

Network::Network( void )
{
	return ;
}
Network::Network( std::string a, int b ) : module(a, b)
{
	return ;
}
Network::Network( const Network &toCopy )
{
	*this = toCopy;
}
Network::~Network( void )
{
	return ;
}

Network			&Network::operator=( const Network &toCopy )
{
	module::operator=(toCopy);
	static_cast<void>(toCopy);

	return *this;
}
