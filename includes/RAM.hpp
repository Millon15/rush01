/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:51:28 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 19:51:29 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAM_HPP
#define RAM_HPP

#include <ACursesModule.hpp>

class RAM : public ACursesModule {

public:
	RAM( void );
	RAM( std::string, int );
	RAM( const RAM & );
	~RAM( void );

	RAM			&operator=( const RAM & );

	void		putInfo( void ) const;

private:


};

#endif												// end of RAM_HPP
