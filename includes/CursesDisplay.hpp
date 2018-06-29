#ifndef CURSESDISPLAY_HPP
#define CURSESDISPLAY_HPP

#include <Name.hpp>
#include <OS.hpp>
#include <Time.hpp>
#include <CPU.hpp>
#include <RAM.hpp>
#include <Network.hpp>
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
	void					switchName( void );
	void					switchOSinfo( void );
	void					switchTime( void );
	// void					switchCPU( void );
	// void					switchRAM( void );
	// void					switchNetwork( void );
	void					switchCols( int );

private:
	ACursesModule		*NameInfo;
	ACursesModule		*OSInfo;
	ACursesModule		*TimeInfo;
	// ACursesModule		*CPUInfo;
	// ACursesModule		*RAMInfo;
	// ACursesModule		*NetworkInfo;

	bool		isName;
	bool		isOSinfo;
	bool		isTime;
	// bool		isCPU;
	// bool		isRAM;
	// bool		isNetwork;

	std::vector<IMonitorModule*>		_modules;
	int									_nbColums;

	void					allocAll( void );
	void					deleteAll( void );
	void					reAllocAll( void );

};

#endif												// end of CURSESDISPLAY_HPP
