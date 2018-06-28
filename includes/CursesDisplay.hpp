#ifndef CURSESDISPLAY_HPP
#define CURSESDISPLAY_HPP

#define EXIT_KEY1 27
#define EXIT_KEY2 113
#define EXIT_KEY3 81

#include <module.hpp>
#include <vector>

class CursesDisplay {

public:
	CursesDisplay( void );
	CursesDisplay( const CursesDisplay & );
	~CursesDisplay( void );

	CursesDisplay			&operator=( const CursesDisplay & );

	void					refresh( void );
	void					hello( void );

private:
	module		*Names;
	module		*OSinfo;
	module		*Time;
	module		*CPU;
	module		*RAM;
	module		*Network;

	std::vector<module*>	_modules;

};

#endif												// end of CURSESDISPLAY_HPP
