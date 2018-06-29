#include <Time.hpp>

Time::Time( void )
{
	return ;
}
Time::Time( std::string a, int b ) : ACursesModule(a, b)
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
	ACursesModule::operator=(toCopy);
	static_cast<void>(toCopy);

	return *this;
}


void			Time::putInfo( void ) const
{
	const std::string	t = this->exec("date '+%d/%m/%Y %H:%M:%S'");

	mvwprintw(this->_w, _winStStr + 2, (__size_x - t.length()) / 2, "%s", t.c_str());

	this->refresh();
}
