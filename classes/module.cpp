#include <module.hpp>

module::module( void ) :
	_motto(""),
	_nbColums(2)
{
	init();
}
module::module( std::string str, int nbColums ) :
	_motto(str),
	_nbColums(nbColums)
{
	init();
}
module::module( const module &toCopy )
{
	*this = toCopy;
}
module::~module( void )
{
	decInitYX();
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
	if ( initial_x == (__size_x * _nbColums) ) {
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
void			module::decInitYX( void )
{
	*_initial_y = 0;
	*_initial_x = 0;
}


														/* GETTERS */
WINDOW			*module::getWin( void )
{
	return this->_w;
}
