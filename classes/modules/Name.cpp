#include <Name.hpp>

Name::Name( void )
{
	return ;
}
Name::Name( std::string a, int b ) : ACursesModule(a, b)
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
	ACursesModule::operator=(toCopy);
	static_cast<void>(toCopy);

	return *this;
}

void			Name::putInfo( void ) const
{
	const std::size_t		len = __size_x - strlen("Hostname: ") - 1;
	char					name[len];

	gethostname(name, len);
	mvwprintw(this->_w, _winStStr, 1, "Username: %s", getenv("USER"));
	mvwprintw(this->_w, _winStStr + 2, 1, "Hostname: %s", name);

	this->refresh();
}
