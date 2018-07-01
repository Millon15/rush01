/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACursesModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:09:12 by vbrazas           #+#    #+#             */
/*   Updated: 2018/07/01 13:35:13 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACURSESMODULE_HPP
#define ACURSESMODULE_HPP


#include <IMonitorModule.hpp>
#include <main.hpp>

class ACursesModule : public IMonitorModule {

public:
	ACursesModule( void );
	ACursesModule( std::string &, int );
	ACursesModule( const ACursesModule & );
	virtual ~ACursesModule( void );

	ACursesModule			&operator=( const ACursesModule & );

	virtual void			refresh( void ) const;
	virtual void			putInfo( void ) const;

	/* GETTERS */
	WINDOW					*getWin( void ) const;

protected:
	WINDOW				*_w;
	int					_borderThick;
	std::string			_motto;
	int					_nbColums;
	int					*_initial_y;
	int					*_initial_x;
	static const int	_winStStr = 3;
	static const int	__size_y = 20;
	static const int	__size_x = 30;

	virtual void		init( void );
	void				decInitYX( void );

	int					alignCenter( const std::string & ) const;
	int					alignCenter( const int ) const;
	int					alignRight( const std::string &str ) const;
	int					alignRight( const int slen ) const;

	void				clearLine( int ) const;
	void				clearWindow( void ) const;

};

#endif												// end of ACURSESMODULE_HPP
