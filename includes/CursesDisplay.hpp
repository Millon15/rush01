/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CursesDisplay.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:08:26 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 22:02:02 by vbrazas          ###   ########.fr       */
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
#include <Cat.hpp>
#include <main.hpp>

class CursesDisplay {

public:
	CursesDisplay( void );
	CursesDisplay( const CursesDisplay & );
	~CursesDisplay( void );

	CursesDisplay			&operator=( const CursesDisplay & );

	void					run( void );

private:
	bool		isName;
	bool		isOSinfo;
	bool		isTime;
	bool		isCPU;
	bool		isRAM;
	bool		isNetworkThro;
	bool		isNetworkInfo;
	bool		isCat;

	std::vector<IMonitorModule*>		_modules;
	int									_nbColums;

	void					refresh( void ) const;
	void					init( void );

	void					allocAll( void );
	void					deleteAll( void );
	void					reAllocAll( void );

	/* Module switchers */
	void					switchName( void );
	void					switchOSinfo( void );
	void					switchTime( void );
	void					switchCPU( void );
	void					switchRAM( void );
	void					switchNetworkThro( void );
	void					switchNetworkInfo( void );
	void					switchCat( void );
	void					switchCols( int );


};

#endif												// end of CURSESDISPLAY_HPP
