#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <iostream>

class IMonitorModule {

public:
	virtual ~IMonitorModule( void ) { return ; };

	virtual void			refresh( void ) = 0;

protected:
	
	virtual void				init( void ) = 0;

};

#endif												// end of IMONITORMODULE_HPP
