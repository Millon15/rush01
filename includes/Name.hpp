/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Name.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:51:18 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 19:51:18 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAME_HPP
#define NAME_HPP

#include <ACursesModule.hpp>

class Name : public ACursesModule {

public:
	Name( void );
	Name( std::string, int );
	Name( const Name & );
	~Name( void );

	Name			&operator=( const Name & );

	virtual void			putInfo( void ) const;

private:


};

#endif												// end of NAME_HPP
