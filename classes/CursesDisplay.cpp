/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CursesDisplay.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:08:22 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 22:01:27 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CursesDisplay.hpp>

// #include <fstream>
// std::ofstream	o("log");
// o << _modules[i] << std::endl;

CursesDisplay::CursesDisplay( void ) : 
	isName(true),
	isOSinfo(true),
	isTime(true),
	isCPU(true),
	isRAM(true),
	isNetworkThro(true),
	isNetworkInfo(true),
	isCat(true),
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

	system("reset; clear; echo '\t\t\t\t\t\tGOODBYE'");
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
	if ( isName )			_modules.push_back(new Name("1. User info", _nbColums));
	if ( isOSinfo )			_modules.push_back(new OS("2. OS info", _nbColums));
	if ( isTime )			_modules.push_back(new Time("3. Time", _nbColums));
	if ( isCPU )			_modules.push_back(new CPU("4. CPU info", _nbColums));
	if ( isRAM )			_modules.push_back(new RAM("5. RAM info", _nbColums));
	if ( isNetworkThro )	_modules.push_back(new NetworkThro("6. Network throughput", _nbColums));
	if ( isNetworkInfo )	_modules.push_back(new NetworkInfo("7. Network interfaces", _nbColums));
	if ( isCat )			_modules.push_back(new Cat("8. Hello Kitty", _nbColums));
}
void						CursesDisplay::reAllocAll( void )
{
	this->deleteAll();

	this->allocAll();

	clear();
}
void						CursesDisplay::refresh( void ) const
{
	for (	std::vector<int>::size_type i = 0;
			i < _modules.size();
			i++ )
	{
		_modules[i]->putInfo();
	}
}


void						CursesDisplay::run( void )
{
	time_t			t = time(NULL);
	int				c;

	while (true)
	{
		c = getch();
		if ( c == KEY_ONE )				this->switchName();
		else if ( c == KEY_TWO )		this->switchOSinfo();
		else if ( c == KEY_THREE )		this->switchTime();
		else if ( c == KEY_FOUR )		this->switchCPU();
		else if ( c == KEY_FIVE )		this->switchRAM();
		else if ( c == KEY_SIX )		this->switchNetworkThro();
		else if ( c == KEY_SEVEN )		this->switchNetworkInfo();
		else if ( c == KEY_EIGHT )		this->switchCat();
		else if ( c == COL_ONE )		this->switchCols(1);
		else if ( c == COL_TWO )		this->switchCols(2);
		else if ( c == COL_THREE )		this->switchCols(3);
		else if ( c == COL_FOUR )		this->switchCols(4);
		else if ( c == COL_FIVE )		this->switchCols(5);
		else if ( c == COL_SIX )		this->switchCols(6);
		else if ( c == EXIT_KEY1 || c == EXIT_KEY2 || c == EXIT_KEY3 )
			break ;

		if ( t != time(NULL) ) {
			this->refresh();
			t = time(NULL);
		}
	}
}


																	/* Module switchers */
void						CursesDisplay::switchName( void )
{
	isName = !isName;
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
void						CursesDisplay::switchNetworkThro( void )
{
	isNetworkThro = !isNetworkThro;
	this->reAllocAll();
}
void						CursesDisplay::switchNetworkInfo( void )
{
	isNetworkInfo = !isNetworkInfo;
	this->reAllocAll();
}
void						CursesDisplay::switchCat( void )
{
	isCat = !isCat;
	this->reAllocAll();
}
void						CursesDisplay::switchCols( int nbColums )
{
	_nbColums = nbColums;
	this->reAllocAll();
}
