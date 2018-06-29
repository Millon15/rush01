#include <CursesDisplay.hpp>

// #include <fstream>
// std::ofstream	o("log");
// o << _modules[i] << std::endl;

CursesDisplay::CursesDisplay( void ) : 
	isNames(true),
	isOSinfo(true),
	isTime(true),
	isCPU(true),
	isRAM(true),
	isNetwork(true),
	_modules(0),
	_nbColums(2)
{
	this->init();
}
CursesDisplay::CursesDisplay( const CursesDisplay &toCopy )
{
	*this = toCopy;
}

CursesDisplay::~CursesDisplay( void )
{

	this->deleteAll();
	endwin();

	system("reset; clear; echo '\t\t\t\t\t\tGOODBUY'");
}

CursesDisplay				&CursesDisplay::operator=( const CursesDisplay &toCopy )
{
	static_cast<void>(toCopy);

	return *this;
}


void						CursesDisplay::init( void )
{
	initscr();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	curs_set(false);
	clear();
	noecho();
	cbreak();
	this->allocAll();
}
void						CursesDisplay::deleteAll( void )
{
	for ( ; _modules.size(); )
	{
		delete _modules.front();
		_modules.erase(_modules.begin());
	}
}
void						CursesDisplay::allocAll( void )
{
	if ( isNames ) {
		Names = new module("1. User info", _nbColums);
		_modules.push_back(Names);
	}

	if ( isOSinfo ) {
		OSinfo = new module("2. OS info", _nbColums);
		_modules.push_back(OSinfo);
	}

	if ( isTime ) {
		Time = new module("3. Time", _nbColums);
		_modules.push_back(Time);
	}

	if ( isCPU ) {
		CPU = new module("4. CPU info", _nbColums);
		_modules.push_back(CPU);
	}

	if ( isRAM ) {
		RAM = new module("5. RAM info", _nbColums);
		_modules.push_back(RAM);
	}

	if ( isNetwork ) {
		Network = new module("6. Network info", _nbColums);
		_modules.push_back(Network);
	}
}
void						CursesDisplay::reAllocAll( void )
{
	this->deleteAll();

	this->allocAll();

	clear();
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

															/* Module switchers */
void						CursesDisplay::switchNames( void )
{
	isNames = !isNames;
	this->reAllocAll();
}
void						CursesDisplay::switchOSinfo( void )
{
	isOSinfo = !isOSinfo;
	this->reAllocAll();
}
void						CursesDisplay::switchTime( void )
{
	isTime = !isTime;
	this->reAllocAll();
}
void						CursesDisplay::switchCPU( void )
{
	isCPU = !isCPU;
	this->reAllocAll();
}
void						CursesDisplay::switchRAM( void )
{
	isRAM = !isRAM;
	this->reAllocAll();
}
void						CursesDisplay::switchNetwork( void )
{
	isNetwork = !isNetwork;
	this->reAllocAll();
}
void						CursesDisplay::switchCols( int nbColums )
{
	_nbColums = nbColums;
	this->reAllocAll();
}
