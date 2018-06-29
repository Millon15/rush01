#ifndef ACURSESMODULE_HPP
#define ACURSESMODULE_HPP


#include <IMonitorModule.hpp>
#include <main.hpp>

class ACursesModule : public IMonitorModule {

public:
	ACursesModule( void );
	ACursesModule( std::string &, int );
	ACursesModule( const ACursesModule & );
	virtual ~ACursesModule( void );

	ACursesModule			&operator=( const ACursesModule & );

	virtual void			refresh( void ) const;
	virtual void			putInfo( void ) const;

	/* GETTERS */
	WINDOW					*getWin( void ) const;

protected:
	WINDOW				*_w;
	std::string			_motto;
	int					_nbColums;
	int					*_initial_y;
	int					*_initial_x;
	static const int	_winStStr = 3;
	static const int	__size_y = 20;
	static const int	__size_x = 30;

	void				decInitYX( void );
	int					alignCenter( const std::string & ) const;
	int					alignCenter( const int ) const;
	virtual void		init( void );

};

#endif												// end of ACURSESMODULE_HPP
