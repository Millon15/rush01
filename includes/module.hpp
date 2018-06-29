#ifndef MODULE_HPP
#define MODULE_HPP

#include <IMonitorModule.hpp>

class module : public IMonitorModule {

public:
	module( void );
	module( std::string, int );
	module( const module & );
	virtual ~module( void );

	module			&operator=( const module & );

	virtual void			refresh( void );

	/* GETTERS */
	WINDOW			*getWin( void );

protected:
	virtual void				init( void );

private:
	WINDOW				*_w;
	std::string			_motto;
	int					_nbColums;
	int					*_initial_y;
	int					*_initial_x;
	static const int	__size_y = 20;
	static const int	__size_x = 30;

	void				decInitYX( void );

};

#endif												// end of MODULE_HPP
