#include <ACursesModule.hpp>

ACursesModule::ACursesModule( void ) :
	_motto(""),
	_nbColums(2)
{
	init();
}
ACursesModule::ACursesModule( std::string str, int nbColums ) :
	_motto(str),
	_nbColums(nbColums)
{
	init();
}
ACursesModule::ACursesModule( const ACursesModule &toCopy )
{
	*this = toCopy;
}
ACursesModule::~ACursesModule( void )
{
	decInitYX();
	wborder(_w, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(_w);
	delwin(_w);
}
ACursesModule				&ACursesModule::operator=( const ACursesModule &toCopy )
{
	static_cast<void>(toCopy);

	return *this;
}


void			ACursesModule::init( void )
{
	static int			initial_y = 0;
	static int			initial_x = 0;

	_initial_y = &initial_y;
	_initial_x = &initial_x;
	_w = newwin(__size_y, __size_x, initial_y, initial_x);
	initial_x += __size_x;
	if ( initial_x == (__size_x * _nbColums) ) {
		initial_y += __size_y;
		initial_x = 0;
	}
}
void			ACursesModule::putInfo( void ) const
{
	return ;
}
void			ACursesModule::refresh( void ) const
{
	mvwprintw(this->_w, 1, (__size_x  - _motto.length()) / 2, "%s", _motto.c_str());
	box(_w, 0, 0);
	wrefresh(_w);
}
void			ACursesModule::decInitYX( void )
{
	*_initial_y = 0;
	*_initial_x = 0;
}
std::string		ACursesModule::exec( const char *cmd ) const
{
	char			buffer[128];
	std::string		result = "";
	FILE*			pipe = popen(cmd, "r");

	if ( !pipe ) throw std::runtime_error("popen() failed!");
	try {
		while (!feof(pipe)) {
			if (fgets(buffer, 128, pipe) != NULL)
				result += buffer;
		}
	}
	catch (...) {
		pclose(pipe);
		throw;
	}
	pclose(pipe);
	return result;
}

														/* GETTERS */
WINDOW			*ACursesModule::getWin( void ) const
{
	return this->_w;
}
