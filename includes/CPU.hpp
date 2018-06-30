/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:50:56 by vbrazas           #+#    #+#             */
/*   Updated: 2018/06/30 19:50:57 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_HPP
#define CPU_HPP

#include <ACursesModule.hpp>

class CPU : public ACursesModule {

public:
	CPU( void );
	CPU( std::string, int );
	CPU( const CPU & );
	~CPU( void );

	CPU			&operator=( const CPU & );

	void		putInfo( void ) const;

private:


};

#endif												// end of CPU_HPP
