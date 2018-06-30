/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkInfo.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:09:07 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 12:15:39 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKINFO_HPP
#define NETWORKINFO_HPP

#include <ACursesModule.hpp>

class NetworkInfo : public ACursesModule {

public:
	NetworkInfo( void );
	NetworkInfo( std::string, int );
	NetworkInfo( const NetworkInfo & );
	~NetworkInfo( void );

	NetworkInfo			&operator=( const NetworkInfo & );

	void			putInfo( void ) const;

private:


};

#endif												// end of NETWORKINFO_HPP
