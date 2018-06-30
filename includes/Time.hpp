/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:51:32 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 19:51:33 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_HPP
#define TIME_HPP

#include <ACursesModule.hpp>

class Time : public ACursesModule {

public:
	Time( void );
	Time( std::string, int );
	Time( const Time & );
	~Time( void );

	Time			&operator=( const Time & );

	void			putInfo( void ) const;

private:


};

#endif												// end of TIME_HPP
