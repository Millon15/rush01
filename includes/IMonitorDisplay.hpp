/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:51:06 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 19:51:07 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

class IMonitorDisplay {

public:
	IMonitorDisplay( void );
	IMonitorDisplay( const IMonitorDisplay & );
	virtual ~IMonitorDisplay( void ) = 0;

private:


};

#endif												// end of IMONITORDISPLAY_HPP
