/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CursesDisplay.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:08:26 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 15:43:19 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSESDISPLAY_HPP
#define CURSESDISPLAY_HPP

#include <Name.hpp>
#include <OS.hpp>
#include <Time.hpp>
#include <CPU.hpp>
#include <RAM.hpp>
#include <NetworkInfo.hpp>
#include <NetworkThro.hpp>
#include <main.hpp>

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
	void					switchCPU( void );
	void					switchRAM( void );
	void					switchNetworkThro( void );
	void					switchNetworkInfo( void );
	// void					switchCat( void );
	// void					switchHardware( void );
	void					switchCols( int );

private:
	ACursesModule		*NameInfo;
	ACursesModule		*OSInfo;
	ACursesModule		*TimeInfo;
	ACursesModule		*CPUInfo;
	ACursesModule		*RAMInfo;
	ACursesModule		*NetworkThr;
	ACursesModule		*NetworkInf;
	// ACursesModule		*CatInst;
	// ACursesModule		*HardW;

	bool		isName;
	bool		isOSinfo;
	bool		isTime;
	bool		isCPU;
	bool		isRAM;
	bool		isNetworkThro;
	bool		isNetworkInfo;
	// bool		isCat;
	// bool		isHardware;

	std::vector<IMonitorModule*>		_modules;
	int									_nbColums;

	void					allocAll( void );
	void					deleteAll( void );
	void					reAllocAll( void );

};

#endif												// end of CURSESDISPLAY_HPP
