#include <CursesDisplay.hpp>

// #include <fstream>
// std::ofstream	o("log");
// o << _modules[i] << std::endl;

CursesDisplay::CursesDisplay( void ) : _modules(0)
{
	initscr();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	curs_set(false);
	clear();
	noecho();
	cbreak();

	Names = new module("User info");
	_modules.push_back(Names);

	OSinfo = new module("OS info");
	_modules.push_back(OSinfo);

	Time = new module("Time");
	_modules.push_back(Time);

	CPU = new module("CPU info");
	_modules.push_back(CPU);

	RAM = new module("RAM info");
	_modules.push_back(RAM);

	Network = new module("Network info");
	_modules.push_back(Network);
}

CursesDisplay::CursesDisplay( const CursesDisplay &toCopy )
{
	*this = toCopy;
}

CursesDisplay::~CursesDisplay( void )
{
	for (	std::vector<int>::size_type i = 0;
		i < _modules.size();
		i++ )
	{
		delete _modules[i];
	}
	endwin();

	system("reset; clear; echo '\t\t\t\t\t\tGOODBUY'");
}

CursesDisplay				&CursesDisplay::operator=( const CursesDisplay &toCopy )
{
	static_cast<void>(toCopy);

	return *this;
}



void						CursesDisplay::refresh( void )
{
	
	for (	std::vector<int>::size_type i = 0;
			i < _modules.size();
			i++ )
	{
		_modules[i]->refresh();
	}
}
void						CursesDisplay::hello( void )
{
	static int i = 1;
	mvwprintw(Names->getWin(), i++, 1, "Hello World!!!");
	box(Names->getWin(), 0, 0);
	wrefresh(Names->getWin());
}
