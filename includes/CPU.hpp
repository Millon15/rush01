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
#include <AGUIModule.hpp>

class CPU : public ACursesModule, public AGUIModule {

public:
	CPU( GtkWidget *window );
	CPU( std::string, int );
	CPU( const CPU & );
	~CPU( void );

	CPU				&operator=( const CPU & );

	virtual void	putInfo( void ) const;

private:
	bool						_isHUI;
	std::vector<GtkWidget*>		_lables;

};

#endif												// end of CPU_HPP
