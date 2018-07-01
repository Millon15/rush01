/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:51:11 by vbrazas           #+#    #+#             */
/*   Updated: 2018/07/01 17:50:10 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

#include <main.hpp>

class IMonitorModule {

public:
	virtual ~IMonitorModule( void ) { return ; };

	virtual void			putInfo( void ) const = 0;

protected:

};

#endif												// end of IMONITORMODULE_HPP
