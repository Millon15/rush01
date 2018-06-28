#ifndef MODULE_HPP
#define MODULE_HPP

#define NB_MODULES_IN_LINE 2

#include <ncurses.h>
#include <cstdlib>
#include <string>

class module {

public:
	module( void );
	module( std::string str );
	module( const module & );
	~module( void );

	module			&operator=( const module & );

	void			init( void );
	void			refresh( void );
	void			decInitXY( void );

	/* GETTERS */
	WINDOW			*getWin( void );
	int				getY( void );
	int				getX( void );
	int				getIY( void );
	int				getIX( void );


private:
	WINDOW				*_w;
	std::string			_motto;
	int					_y;
	int					_x;
	int					*_initial_y;
	int					*_initial_x;
	static const int	__size_y = 20;
	static const int	__size_x = 30;


};

#endif												// end of MODULE_HPP
