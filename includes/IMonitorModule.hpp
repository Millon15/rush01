/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:51:11 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 19:51:12 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

class IMonitorModule {

public:
	virtual ~IMonitorModule( void ) { return ; };

	virtual void			refresh( void ) const = 0;
	virtual void			putInfo( void ) const = 0;

protected:
	
	virtual void				init( void ) = 0;

};

#endif												// end of IMONITORMODULE_HPP
