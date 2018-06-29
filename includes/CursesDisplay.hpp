#ifndef CURSESDISPLAY_HPP
#define CURSESDISPLAY_HPP

#include <module.hpp>
#include <vector>

class CursesDisplay {

public:
	CursesDisplay( void );
	CursesDisplay( const CursesDisplay & );
	~CursesDisplay( void );

	CursesDisplay			&operator=( const CursesDisplay & );

	void					refresh( void );
	void					init( void );

	/* Module switchers */
	void					switchNames( void );
	void					switchOSinfo( void );
	void					switchTime( void );
	void					switchCPU( void );
	void					switchRAM( void );
	void					switchNetwork( void );
	void					switchCols( int );

private:
	module		*Names;
	module		*OSinfo;
	module		*Time;
	module		*CPU;
	module		*RAM;
	module		*Network;

	bool		isNames;
	bool		isOSinfo;
	bool		isTime;
	bool		isCPU;
	bool		isRAM;
	bool		isNetwork;

	std::vector<module*>	_modules;
	int						_nbColums;

	void					allocAll( void );
	void					deleteAll( void );
	void					reAllocAll( void );

};

#endif												// end of CURSESDISPLAY_HPP
