/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkThro.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:06:41 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 15:42:42 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKTHRO_HPP
#define NETWORKTHRO_HPP

#include <ACursesModule.hpp>

class NetworkThro : public ACursesModule {

public:
	NetworkThro( void );
	NetworkThro( std::string, int );
	NetworkThro( const NetworkThro & );
	~NetworkThro( void );

	NetworkThro			&operator=( const NetworkThro & );

	virtual void			putInfo( void ) const;

private:


};

#endif												// end of NETWORKTHRO_HPP
