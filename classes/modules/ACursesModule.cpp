/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACursesModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:09:10 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 19:34:22 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ACursesModule.hpp>

ACursesModule::ACursesModule( void ) :
	_motto(""),
	_nbColums(2)
{
	init();
}
ACursesModule::ACursesModule( std::string &str, int nbColums ) :
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
	mvwprintw(this->_w, 1, alignCenter(_motto), "%s", _motto.c_str());
	box(_w, 0, 0);
}
void			ACursesModule::putInfo( void ) const
{
	return ;
}


void			ACursesModule::refresh( void ) const
{
	box(_w, 0, 0);
	wrefresh(_w);
}
int				ACursesModule::alignCenter( const std::string &str, int borderThick ) const
{
	const int		len = (__size_x - str.length()) / 2;

	if ( len > borderThick ) {
		return len;
	}
	else {
		return borderThick;
	}
}
int				ACursesModule::alignCenter( const int slen, int borderThick ) const
{
	const int		len = (__size_x - slen) / 2;

	if ( len > borderThick ) {
		return len;
	}
	else {
		return borderThick;
	}
}
int				ACursesModule::alignRight( const std::string &str, int borderThick ) const
{
	const int		len = __size_x - str.length() - borderThick;

	if ( len > borderThick ) {
		return len;
	}
	else {
		return borderThick;
	}
}
int				ACursesModule::alignRight( const int slen, int borderThick ) const
{
	const int		len = __size_x - slen - borderThick;

	if ( len > borderThick ) {
		return len;
	}
	else {
		return borderThick;
	}
}
void			ACursesModule::decInitYX( void )
{
	*_initial_y = 0;
	*_initial_x = 0;
}
void			ACursesModule::clearLine( int line, int borderThick ) const
{
	std::string		spaces( __size_x - (borderThick * 2), ' ' );

	mvwprintw(this->_w, line, borderThick, "%s", spaces.c_str());
}
void			ACursesModule::clearWindow( int borderThick ) const
{
	const int	bottom = __size_y - borderThick;

	for ( int i = borderThick; i < bottom; i++ ) {
		this->clearLine(i, borderThick);
	}
}



														/* GETTERS */
WINDOW			*ACursesModule::getWin( void ) const
{
	return this->_w;
}
