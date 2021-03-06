/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:51:24 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 19:51:24 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OS_HPP
#define OS_HPP

#include <ACursesModule.hpp>

class OS : public ACursesModule {

public:
	OS( void );
	OS( std::string, int );
	OS( const OS & );
	~OS( void );

	OS			&operator=( const OS & );

	void		putInfo( void ) const;

private:


};

#endif												// end of OS_HPP
