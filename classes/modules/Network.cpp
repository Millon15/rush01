#include <Network.hpp>

Network::Network( void )
{
	return ;
}
Network::Network( std::string a, int b ) : ACursesModule(a, b)
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
	ACursesModule::operator=(toCopy);
	static_cast<void>(toCopy);

	return *this;
}


void			Network::putInfo( void ) const
{
	const std::string	c1 = saveExec(\
	"cat sysInfo | grep -A 29 'Network:' | grep '\\w:$' | awk '{gsub(\":\", \"\", $1); gsub(\":\", \"\", $2); printf \"%s%s \", $1, $2}'");

	mvwprintw(this->_w, _winStStr, 1, "%s", c1.c_str());

	this->refresh();
}
