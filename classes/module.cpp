#include <module.hpp>

module::module( void ) :
	_motto(""),
	_y(0),
	_x(0)
{
	init();
}
module::module( std::string str ) :
	_motto(str),
	_y(0),
	_x(0)
{
	init();
}
module::module( const module &toCopy )
{
	*this = toCopy;
}
module::~module( void )
{
	wborder(_w, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(_w);
	delwin(_w);
}
module				&module::operator=( const module &toCopy )
{
	static_cast<void>(toCopy);

	return *this;
}


void			module::init( void )
{
	static int			initial_y = 0;
	static int			initial_x = 0;

	_initial_y = &initial_y;
	_initial_x = &initial_x;
	_w = newwin(__size_y, __size_x, initial_y, initial_x);
	initial_x += __size_x;
	if ( initial_x == (__size_x * NB_MODULES_IN_LINE) ) {
		initial_y += __size_y;
		initial_x = 0;
	}
}

void			module::refresh( void )
{
	mvwprintw(this->_w, 1, (__size_x  - _motto.length()) / 2, "%s", _motto.c_str());
	box(_w, 0, 0);
	wrefresh(_w);
}

void			module::decInitXY( void )
{
	if ( *_initial_y != 0 && *_initial_x != 0 ) {
		*_initial_y -= __size_y;
		*_initial_x -= __size_x;
	}
}


														/* GETTERS */
WINDOW			*module::getWin( void )
{
	return this->_w;
}
int				module::getY( void )
{
	return this->_y;
}
int				module::getX( void )
{
	return this->_x;
}
int				module::getIY( void )
{
	return *this->_initial_y;
}
int				module::getIX( void )
{
	return *this->_initial_x;
}
