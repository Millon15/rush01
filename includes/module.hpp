#ifndef MODULE_HPP
#define MODULE_HPP

#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <iostream>

class module {

public:
	module( void );
	module( std::string, int );
	module( const module & );
	~module( void );

	module			&operator=( const module & );

	void			refresh( void );

	/* GETTERS */
	WINDOW			*getWin( void );

private:
	WINDOW				*_w;
	std::string			_motto;
	int					_nbColums;
	int					*_initial_y;
	int					*_initial_x;
	static const int	__size_y = 20;
	static const int	__size_x = 30;

	void				init( void );
	void				decInitYX( void );

};

#endif												// end of MODULE_HPP
