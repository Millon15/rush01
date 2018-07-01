/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACursesModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:09:10 by vbrazas           #+#    #+#             */
/*   Updated: 2018/07/01 14:16:35 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ACursesModule.hpp>

ACursesModule::ACursesModule( void ) :
	_borderThick(1),
	_motto(""),
	_nbColums(2)
{
	init();
}
ACursesModule::ACursesModule( std::string &str, int nbColums ) :
	_borderThick(1),
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
	this->refresh();
}
void			ACursesModule::putInfo( void ) const
{
	return ;
}


void			ACursesModule::refresh( void ) const
{
	wattron( _w, COLOR_PAIR(HEADING) | A_BOLD );
	mvwprintw(this->_w, 1, alignCenter(_motto), "%s", _motto.c_str());
	wattroff( _w, COLOR_PAIR(HEADING) | A_BOLD );

	box(_w, 0, 0);

	wrefresh(_w);
}
int				ACursesModule::alignCenter( const std::string &str ) const
{
	const int		len = (__size_x - str.length()) / 2;

	if ( len > _borderThick ) {
		return len;
	}
	else {
		return _borderThick;
	}
}
int				ACursesModule::alignCenter( const int slen ) const
{
	const int		len = (__size_x - slen) / 2;

	if ( len > _borderThick ) {
		return len;
	}
	else {
		return _borderThick;
	}
}
int				ACursesModule::alignRight( const std::string &str ) const
{
	const int		len = __size_x - str.length() - _borderThick;

	if ( len > _borderThick ) {
		return len;
	}
	else {
		return _borderThick;
	}
}
int				ACursesModule::alignRight( const int slen ) const
{
	const int		len = __size_x - slen - _borderThick;

	if ( len > _borderThick ) {
		return len;
	}
	else {
		return _borderThick;
	}
}
void			ACursesModule::decInitYX( void )
{
	*_initial_y = 0;
	*_initial_x = 0;
}
void			ACursesModule::clearLine( int line ) const
{
	std::string		spaces( __size_x - (_borderThick * 2), ' ' );

	mvwprintw(this->_w, line, _borderThick, "%s", spaces.c_str());
}
void			ACursesModule::clearWindow( void ) const
{
	const int	bottom = __size_y - _borderThick;

	for ( int i = _borderThick; i < bottom; i++ ) {
		this->clearLine(i);
	}
}


															/* GETTERS */
WINDOW			*ACursesModule::getWin( void ) const
{
	return this->_w;
}
