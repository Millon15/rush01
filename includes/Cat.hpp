/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:50:48 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 21:02:15 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <ACursesModule.hpp>

class Cat : public ACursesModule {

public:
	Cat( void );
	Cat( std::string, int );
	Cat( const Cat & );
	~Cat( void );

	Cat			&operator=( const Cat & );

	void		putInfo( void ) const;

private:
	std::vector<std::string>		_kitty;

	void				kittyInit( void );

};

#endif												// end of CAT_HPP
